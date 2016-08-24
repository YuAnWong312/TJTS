#ifndef QTLOGICCONTROL_H
#define QTLOGICCONTROL_H 1

#if	defined(QTLOGICCONTROL_STATIC)
# define QTLOGICCONTROL_EXPORT
#elif defined(QTLOGICCONTROL_DYNAMIC)
# define QTLOGICCONTROL_EXPORT __declspec(dllexport)
#else
# define QTLOGICCONTROL_EXPORT __declspec(dllimport)
#endif
	
#endif // EXPORT_H
