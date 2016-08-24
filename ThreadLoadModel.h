#ifndef THREADLOADMODEL_H_
#define THREADLOADMODEL_H_ 1

#include <OpenThreads/Atomic>
#include <osg/OperationThread>
#include <osg/observer_ptr>
#include <osg/MixinVector>
#include <osgGA/GUIEventHandler>
#include <osgDB/ReaderWriter>
#include <osgUtil/IncrementalCompileOperation>

#include <osgScene/LoadFile.h>
#include <osgScene/Export.h>

namespace osgScene
{
	class OSGSCENE_EXPORT ThreadLoadModel : public osgGA::GUIEventHandler
	{
	public:
		ThreadLoadModel();
		virtual ~ThreadLoadModel();

		class Request;
		class OSGSCENE_EXPORT Operation : public osg::Referenced
		{
		public:
			Operation();
			virtual ~Operation();

			virtual void operator () (Request*) = 0;
		};

        /*
		class OSGSCENE_EXPORT Request : public LoadFilePercentObserver
		{
		public:
			Request();
			Request(const std::string& file, osg::Group* parent, ThreadLoadModel::Operation* op, osgDB::Options* opt, bool needToCompile = true);
			virtual ~Request();
			
			void percent(int percent);
			void percent(float percent);

		public:
			std::string fileName;
			osg::observer_ptr<osg::Group> parent;

			friend class Operation;
			osg::ref_ptr<Operation> operation;
			
			osg::ref_ptr<osgDB::Options> option;
			bool needToCompile;
			
			typedef osgDB::ReaderWriter::ReadResult ReadResult;
			ReadResult rr;
			bool isLoadAndCompile;
			float readPercent;
		};
        */

		class OSGSCENE_EXPORT ReadThread : public osg::Referenced, public OpenThreads::Thread
		{
		public:
			ReadThread(ThreadLoadModel* tlm);

			virtual int cancel();
			virtual void run();
			
			void setDone(bool done) { _done.exchange(done?1:0); }
			bool getDone() { return _done!=0; }

		protected:
			virtual ~ReadThread();

			OpenThreads::Atomic _done;
			ThreadLoadModel* _threadLoadModel;
		};

		friend class ReadThread;
		typedef osg::MixinVector< osg::ref_ptr<ThreadLoadModel::ReadThread> > ThreadList;

		class OSGSCENE_EXPORT ReadQueue : public osg::Referenced
		{
		public:
			ReadQueue();
			typedef std::list< osg::ref_ptr<Request> > RequestList;

			virtual void add(Request* re);
			virtual void remove(Request* re);
			virtual bool empty();
			virtual void clear();

			virtual void takeFirst(osg::ref_ptr<Request>& re);
			virtual void swap(RequestList& rl);

			virtual void updateBlock();
			void block() { _block->block(); }
			void release() { _block->release(); }

		protected:
			OpenThreads::Mutex _mutex;
			osg::ref_ptr<osg::RefBlock> _block;
			RequestList        _requestList;
		};

		class OSGSCENE_EXPORT CompileFinishCallback : public osgUtil::IncrementalCompileOperation::CompileCompletedCallback
		{
		public:
			CompileFinishCallback(ThreadLoadModel* tlm, ThreadLoadModel::Request* request);

			virtual bool compileCompleted(osgUtil::IncrementalCompileOperation::CompileSet* set);


		protected:
			ThreadLoadModel* _tlm;
			osg::ref_ptr<ThreadLoadModel::Request> _request;
		};
		friend class CompileFinishCallback;

		virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);
		virtual void handleOperationQueue();
		virtual void handleAddToSceneQueue();

		virtual void LoadModel(ThreadLoadModel::Request* re);
		virtual void LoadModel(const std::string& file, osg::Group* parent, ThreadLoadModel::Operation* op, osgDB::Options* opt, bool needToCompile = true);

		virtual void compileCompleted(Request* request);

		void setReadThreadNum(int num) { _readThreadNum = num; }
		int getReadThreadNum() { return _readThreadNum; }
		virtual void setUpThreads(unsigned int num = 2);
		virtual void cancel();

		void setIncrementalCompileOperation(osgUtil::IncrementalCompileOperation* ico);

	protected:


	protected:
		osg::ref_ptr<ReadQueue>		_fileRequestQueue;		//read
		osg::ref_ptr<ReadQueue>		_fileOperationQueue;	//operation
		osg::ref_ptr<ReadQueue>		_fileAddToSceneQueue;	//addchild

		int							_readThreadNum;
		ThreadList					_threads;
		bool						_doPreCompile;
		osg::ref_ptr<osgUtil::IncrementalCompileOperation> _incrementalCompileOperation;

		OpenThreads::Mutex _mutex;
	};
}

#endif
