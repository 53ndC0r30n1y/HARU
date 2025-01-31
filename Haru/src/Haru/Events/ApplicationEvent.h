/*
===========================================================================
 @author  : Merely Reed
 @date    : 2024-08-31 13:53
 @file    : ApplicationEvent.h
 @brief   : Define the application event type.
===========================================================================
*/

#ifndef APPLICATIONEVENT_H
#define APPLICATIONEVENT_H

#include "Event.h"
/***********************************************************************

  Application Event

***********************************************************************/

namespace Haru {
/*
============================================================================
 WindowResizeEvent
============================================================================
*/
class HARU_API WindowResizeEvent : public Event {
public:
  WindowResizeEvent(unsigned int width, unsigned int height): m_Width(width), m_Height(height) { }
  inline unsigned int GetWidth() const { return m_Width; }
  inline unsigned int GetHeight() const { return m_Height; }
  std::string         ToString() const override {
    std::stringstream ss;
    ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
    return ss.str();
  }
  EVENT_CLASS_TYPE(WindowResize)
  EVENT_CLASS_CATEGORY(EventCategoryApplication)
private:
  unsigned int m_Width, m_Height;
};
/*
============================================================================
 WindowCloseEvent
============================================================================
*/
class HARU_API WindowCloseEvent : public Event {
public:
  WindowCloseEvent() { }
  EVENT_CLASS_TYPE(WindowClose)
  EVENT_CLASS_CATEGORY(EventCategoryApplication)
};
/*
============================================================================
 AppTickEvent
============================================================================
*/
class HARU_API AppTickEvent : public Event {
public:
  AppTickEvent() { }
  EVENT_CLASS_TYPE(AppTick)
  EVENT_CLASS_CATEGORY(EventCategoryApplication)
};
/*
============================================================================
 AppUpdateEvent
============================================================================
*/
class HARU_API AppUpdateEvent : public Event {
public:
  AppUpdateEvent() { }
  EVENT_CLASS_TYPE(AppUpdate)
  EVENT_CLASS_CATEGORY(EventCategoryApplication)
};
/*
============================================================================
 AppRenderEvent
============================================================================
*/
class HARU_API AppRenderEvent : public Event {
public:
  AppRenderEvent() { }
  EVENT_CLASS_TYPE(AppRender)
  EVENT_CLASS_CATEGORY(EventCategoryApplication)
};
} // namespace Haru

#endif