/*
===========================================================================
 @author  : Merely Reed
 @date    : 2024-09-12 10:32
 @file    : GraphicsContext.h
 @brief   :
===========================================================================
*/

#ifndef GRAPHICSCONTEXT_H
#define GRAPHICSCONTEXT_H

namespace Haru {
/***********************************************************************

  GraphicsContext

***********************************************************************/

class GraphicsContext {
public:
  virtual void Init()        = 0;
  virtual void SwapBuffers() = 0;
};
} // namespace Haru

#endif // !GRAPHICSCONTEXT_H
