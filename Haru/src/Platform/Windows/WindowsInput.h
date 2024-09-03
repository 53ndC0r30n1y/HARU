/*
===========================================================================
 @author  : Merely Reed
 @date    : 2024-08-31 13:53
 @file    : WindowsInput.h
 @brief   :
===========================================================================
*/

#ifndef WINDOWSINPUT_H
#define WINDOWSINPUT_H

#include "Haru/Input.h"

namespace Haru {
/***********************************************************************

  Windows Input

***********************************************************************/

class WindowsInput : public Input {
protected:
  virtual bool IsKeyPressedImpl(int keycode) override;

  virtual bool                    IsMouseButtonPressedImpl(int button) override;
  virtual std::pair<float, float> GetMousePositionImpl() override;
  virtual float                   GetMouseXImpl() override;
  virtual float                   GetMouseYImpl() override;
};

} // namespace Haru
#endif // !WINDOWSINPUT_H