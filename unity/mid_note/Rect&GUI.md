> 現在都用canvas、UI 了，比較少用這個

# Rect(*rectangle*)

* 定義: 由 X 和 Y 位置、寬度和高度定義的 2D 矩形。

* 要顯示矩形要由GUI去顯示

  ```
  				// id從0開始(第一個)
  clientRect = GUI.Window(int id, Rect clientRect,  
  						GUI.WindowFunction func, 填入字串或文字類型或圖片類型);
  
  					// 這裡只要類型是int就好，變數可以隨便取
  void WindowFunction(int id{}
  ```

  ```
  GUI.Box(clientRect, "");  // 這個也可以顯示，不過可變性較低
  ```

  

  

![rect](/picture/Rect.png)

### Constructors

| 建立Rect | Rect rect = new Rect(x, y, width, height) |
| -------- | ----------------------------------------- |
|          |                                           |

### Static Properties

| zero | Rect.zero 跟 new Rect(0,0,0,0) 是一樣的 |
| ---- | --------------------------------------- |
|      |                                         |

### Properties

|  center  | 改變位置 -- 對矩形中心位置做調整   | rect.center = new Vector2(10, 10);    |
| :------: | :--------------------------------- | ------------------------------------- |
| position | 改變位置 -- 對矩形左上位置做調整   | rect.position =  new Vector2(x, y);   |
|    x     | 改變位置 -- 對矩形的x位置做調整    | rect.x += 20;                         |
|    y     | 改變位置 -- 對矩形的y位置做調整    | rect.y += 20;                         |
|  height  | 改變大小 -- 改變矩形的高度         |                                       |
|  width   | 改變大小 -- 改變矩形的寬度         |                                       |
|   size   | 改變大小 -- 改變矩形的大小(改寬高) | rect.size new Vector2(width, height); |

### Public Methods

| Contains | 放入條件，可以用if判斷，執行code                             | if (rect.Contains(Input.mousePosition))             |
| -------- | ------------------------------------------------------------ | --------------------------------------------------- |
| Overlaps | 兩個rect碰到時候為true，allowinverse預設為true，如果是false，長和寬就可以是負的 | if (rect.Overlaps(Rect other, bool   allowInverse)) |
| Set      | 可以用這個修改已存在的rect                                   | rect.Set(x, y, width, height)                       |





# GUI(*Graphical User Interface*)

### Static Properties

| [backgroundColor](https://docs.unity3d.com/ScriptReference/GUI-backgroundColor.html) | Global tinting color for all background elements rendered by the GUI. |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [changed](https://docs.unity3d.com/ScriptReference/GUI-changed.html) | Returns true if any controls changed the value of the input data. |
| [color](https://docs.unity3d.com/ScriptReference/GUI-color.html) | Global tinting color for the GUI.                            |
| [contentColor](https://docs.unity3d.com/ScriptReference/GUI-contentColor.html) | Tinting color for all text rendered by the GUI.              |
| [depth](https://docs.unity3d.com/ScriptReference/GUI-depth.html) | The sorting depth of the currently executing GUI behaviour.  |
| [enabled](https://docs.unity3d.com/ScriptReference/GUI-enabled.html) | Is the GUI enabled?                                          |
| [matrix](https://docs.unity3d.com/ScriptReference/GUI-matrix.html) | The GUI transform matrix.                                    |
| [skin](https://docs.unity3d.com/ScriptReference/GUI-skin.html) | The global skin to use.                                      |
| [tooltip](https://docs.unity3d.com/ScriptReference/GUI-tooltip.html) | The tooltip of the control the mouse is currently over, or which has keyboard focus. (Read Only). |

### Static Methods

| BeginGroup                                                   | Begin a group. Must be matched with a call to EndGroup.      |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| BeginScrollView                                              | Begin a scrolling view inside your GUI.                      |
| Box                                                          | Create a Box on the GUI Layer.                               |
| [BringWindowToBack](https://docs.unity3d.com/ScriptReference/GUI.BringWindowToBack.html) | Bring a specific window to back of the floating windows.     |
| [BringWindowToFront](https://docs.unity3d.com/ScriptReference/GUI.BringWindowToFront.html) | Bring a specific window to front of the floating windows.    |
| [Button](https://docs.unity3d.com/ScriptReference/GUI.Button.html) | Make a single press button. The user clicks them and something happens immediately. |
| [DragWindow](https://docs.unity3d.com/ScriptReference/GUI.DragWindow.html) | Make a window draggable.                                     |
| [DrawTexture](https://docs.unity3d.com/ScriptReference/GUI.DrawTexture.html) | Draw a texture within a rectangle.                           |
| [DrawTextureWithTexCoords](https://docs.unity3d.com/ScriptReference/GUI.DrawTextureWithTexCoords.html) | Draw a texture within a rectangle with the given texture coordinates. |
| [EndGroup](https://docs.unity3d.com/ScriptReference/GUI.EndGroup.html) | End a group.                                                 |
| [EndScrollView](https://docs.unity3d.com/ScriptReference/GUI.EndScrollView.html) | Ends a scrollview started with a call to BeginScrollView.    |
| [FocusControl](https://docs.unity3d.com/ScriptReference/GUI.FocusControl.html) | Move keyboard focus to a named control.                      |
| [FocusWindow](https://docs.unity3d.com/ScriptReference/GUI.FocusWindow.html) | Make a window become the active window.                      |
| [GetNameOfFocusedControl](https://docs.unity3d.com/ScriptReference/GUI.GetNameOfFocusedControl.html) | Get the name of named control that has focus.                |
| [HorizontalScrollbar](https://docs.unity3d.com/ScriptReference/GUI.HorizontalScrollbar.html) | Make a horizontal scrollbar. Scrollbars are what you use to scroll through a document. Most likely, you want to use scrollViews instead. |
| [HorizontalSlider](https://docs.unity3d.com/ScriptReference/GUI.HorizontalSlider.html) | A horizontal slider the user can drag to change a value between a min and a max. |
| [Label](https://docs.unity3d.com/ScriptReference/GUI.Label.html) | Make a text or texture label on screen.                      |
| [ModalWindow](https://docs.unity3d.com/ScriptReference/GUI.ModalWindow.html) | Show a Modal Window.                                         |
| [PasswordField](https://docs.unity3d.com/ScriptReference/GUI.PasswordField.html) | Make a text field where the user can enter a password.       |
| [RepeatButton](https://docs.unity3d.com/ScriptReference/GUI.RepeatButton.html) | Make a button that is active as long as the user holds it down. |
| [ScrollTo](https://docs.unity3d.com/ScriptReference/GUI.ScrollTo.html) | Scrolls all enclosing scrollviews so they try to make position visible. |
| [SelectionGrid](https://docs.unity3d.com/ScriptReference/GUI.SelectionGrid.html) | Make a grid of buttons.                                      |
| [SetNextControlName](https://docs.unity3d.com/ScriptReference/GUI.SetNextControlName.html) | Set the name of the next control.                            |
| [TextArea](https://docs.unity3d.com/ScriptReference/GUI.TextArea.html) | Make a Multi-line text area where the user can edit a string. |
| [TextField](https://docs.unity3d.com/ScriptReference/GUI.TextField.html) | Make a single-line text field where the user can edit a string. |
| [Toggle](https://docs.unity3d.com/ScriptReference/GUI.Toggle.html) | Make an on/off toggle button.                                |
| [Toolbar](https://docs.unity3d.com/ScriptReference/GUI.Toolbar.html) | Make a toolbar.                                              |
| [UnfocusWindow](https://docs.unity3d.com/ScriptReference/GUI.UnfocusWindow.html) | Remove focus from all windows.                               |
| [VerticalScrollbar](https://docs.unity3d.com/ScriptReference/GUI.VerticalScrollbar.html) | Make a vertical scrollbar. Scrollbars are what you use to scroll through a document. Most likely, you want to use scrollViews instead. |
| [VerticalSlider](https://docs.unity3d.com/ScriptReference/GUI.VerticalSlider.html) | A vertical slider the user can drag to change a value between a min and a max. |
| [Window](https://docs.unity3d.com/ScriptReference/GUI.Window.html) | Make a popup window.                                         |

### Delegates

| [WindowFunction](https://docs.unity3d.com/ScriptReference/GUI.WindowFunction.html) | Callback to draw GUI within a window (used with GUI.Window). |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
|                                                              |                                                              |



















> 參考網站: https://docs.unity3d.com/Manual/index.html