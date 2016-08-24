#ifndef QTUPDATE_H
#define QTUPDATE_H 1

#if	defined(QTUPDATE_STATIC)
# define QTUPDATE_EXPORT
#elif defined(QTUPDATE_DYNAMIC)
# define QTUPDATE_EXPORT __declspec(dllexport)
#else
# define QTUPDATE_EXPORT __declspec(dllimport)
#endif
	
#endif // EXPORT_H
