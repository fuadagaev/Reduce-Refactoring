%
% Status:       Open Source: BSD License
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.

% $Id$

(compiletime
(DE  !*ForeignLink (FunctionName  FunctionType NumberOfArguments)
     (codedeclareexternal FunctionName)
     (append (cond ((greaterp NumberOfArguments 5)
			 '((*move (fluid argumentblock) (reg t1))))
		   (t '((*move (reg t1) (reg t1)))))
     (append (pnth '((*move (displacement (reg t1) 32) (reg t2))
                (*push (reg t2))
                (*move (displacement (reg t1) 28) (reg t2))
                (*push (reg t2))
                (*move (displacement (reg t1) 24) (reg t2))
                (*push (reg t2))
                (*move (displacement (reg t1) 20) (reg t2))
                (*push (reg t2))
                (*move (displacement (reg t1) 16) (reg t2))
                (*push (reg t2))
                (*move (displacement (reg t1) 12) (reg t2))
                (*push (reg t2))
                (*move (displacement (reg t1) 8) (reg t2))
                (*push (reg t2))
                (*move (displacement (reg t1) 4) (reg t2))
                (*push (reg t2))
                (*move (displacement (reg t1) 0) (reg t2))
                (*push (reg t2))
	 	(*move (reg t1) (reg t1))(!*PUSH (REG  5))
        	(*move (reg t1) (reg t1))(!*PUSH (REG  4))
		(*move (reg t1) (reg t1))(!*PUSH (REG  3))
		(*move (reg t1) (reg t1))(!*PUSH (REG  2))
		(*move (reg t1) (reg t1))(!*PUSH (REG  1)))

			(difference 30  (times2 2 NumberOfArguments)))
          (append
           (list (list '!*move '(fluid ebxsave!*) '(reg 2))
                 (list 'call (list 'ForeignEntry FunctionName))
                 (list '!*move '(reg 2) '(fluid ebxsave!*)))
           (cond
        ((eq NumberOfArguments 0) nil)
        ((lessp NumberOfArguments 3)
         (list (list 'add (times 4 NumberOfArguments) '(reg st))))
        (t
         (list (list 'add (times 4 NumberOfArguments) '(reg st))))
        ))
           )))
)

% from tk.h
%
%/*
%*--------------------------------------------------------------
%*
%* Exported procedures and variables.
%*
%*--------------------------------------------------------------
%*/

(compiletime (input-case nil))

(off r2i)

(external-function Tk_3DBorderColor (border))
(external-function Tk_3DBorderGC(tkwin border which))
(external-function Tk_3DHorizontalBevel (tkwin drawable border x 
   y width height leftIn rightIn topBevel relief))
(external-function Tk_3DVerticalBevel (tkwin drawable border x 
   y width height leftBevel relief))
(external-function Tk_AddOption (tkwin name value priority))
(external-function Tk_BindEvent (bindingTable 
   eventPtr tkwin numObjects objectPtr))
%% (external-function Tk_CanvasDashParseProc (clientData interp 
%%   tkwin  value widgRec offset))
%% (external-function Tk_CanvasDashPrintProc (clientData tkwin 
%%   widgRec offset freeProcPtr))
(external-function Tk_CanvasDrawableCoords (canvas x y drawableXPtr drawableYPtr))
(external-function Tk_CanvasEventuallyRedraw ( canvas x1 y1 x2 y2))
(external-function Tk_CanvasGetCoord (interp canvas string doublePtr))
(external-function Tk_CanvasGetCoordFromObj (interp canvas obj doublePtr))
(external-function Tk_CanvasGetTextInfo (canvas))
(external-function Tk_CanvasPsBitmap (interp canvas bitmap x y width height))
(external-function Tk_CanvasPsColor (interp canvas colorPtr))
(external-function Tk_CanvasPsFont (interp canvas font))
(external-function Tk_CanvasPsPath (interp canvas coordPtr numPoints))
(external-function Tk_CanvasPsStipple (interp canvas bitmap))
(external-function Tk_CanvasPsY (canvas y))
(external-function Tk_CanvasSetOffset ( canvas gc offset))
(external-function Tk_CanvasSetStippleOrigin (canvas gc))
(external-function Tk_CanvasTagsParseProc ( clientData interp tkwin value widgRec 
   offset))
(external-function Tk_CanvasTagsPrintProc ( clientData tkwin widgRec offset 
		freeProcPtr))
(external-function Tk_CanvasTkwin (canvas))
(external-function Tk_CanvasWindowCoords (canvas x y screenXPtr screenYPtr))
(external-function Tk_ChangeWindowAttributes (tkwin valueMask attsPtr))
(external-function Tk_CharBbox (layout index xPtr yPtr widthPtr heightPtr))
(external-function Tk_ClearSelection (tkwin selection))
(external-function Tk_ClipboardAppend (interp tkwin target format buffer))
(external-function Tk_ClipboardClear (interp tkwin))
(external-function Tk_ConfigureInfo (interp tkwin specs widgRec aargvName flags))
(external-function Tk_ConfigureValue (interp tkwin specs widgRec aargvName flags))
(external-function Tk_ConfigureWidget (interp tkwin specs aargc aargv widgRec flags))
(external-function Tk_ConfigureWindow (tkwin unsignedvalueMask valuePtr))
(external-function Tk_ComputeTextLayout (font string numChars wrapLength 
	 justify flags widthPtr heightPtr))
(external-function Tk_CoordsToWindow (rootX rootY tkwin))
(external-function Tk_CreateBinding (interp bindingTable object 
   eventString command append))
(external-function Tk_CreateBindingTable (interp))
(external-function Tk_CreateErrorHandler (display 
   errNum request minorCode Tk_ErrorProc errorProc clientData))
(external-function Tk_CreateEventHandler (token mask proc clientData))
(external-function Tk_CreatePhotoOption (interp name  proc))
(external-function Tk_CreateGenericHandler ( proc clientData))
(external-function Tk_CreateImageType ( Tk_ImageType typePtr))
(external-function Tk_CreateItemType (Tk_ItemType typePtr))
(external-function Tk_CreatePhotoImageFormat (formatPtr))
(external-function Tk_CreateSelHandler (tkwin 
   selection target proc clientData format))
(external-function Tk_CreateSmoothMethod (interp Tk_SmoothMethod method))
%%(external-function Tk_CreateCanvasVisitor (interp typePtr))
(external-function Tk_CreateWindow (interp parent name screenName))
(external-function Tk_CreateWindowFromPath ( interp tkwin 
   pathName screenName))
(external-function Tk_DefineBitmap (interp name source width height))
(external-function Tk_DefineCursor (window cursor))
(external-function Tk_DeleteAllBindings ( bindingTable object))
(external-function Tk_DeleteBinding (interp bindingTable object eventString))
(external-function Tk_DeleteBindingTable ( bindingTable))
(external-function Tk_DeleteErrorHandler ( handler))
(external-function Tk_DeleteEventHandler (token mask proc clientData))
(external-function Tk_DeleteGenericHandler ( proc clientData))
(external-function Tk_DeleteImage (interp name))
(external-function Tk_DeleteSelHandler (tkwin selection target))
(external-function Tk_DestroyWindow (tkwin))
(external-function Tk_DisplayName (tkwin))
(external-function Tk_DitherPhoto (handle x y width height))
(external-function Tk_DistanceToTextLayout ( layout x y))
(external-function Tk_Draw3DPolygon (tkwin drawable border pointPtr 
	numPoints borderWidth leftRelief))
(external-function Tk_Draw3DRectangle (tkwin drawable border x 
	y width height borderWidth relief))
(external-function Tk_DrawChars (display drawable gc tkfont source numChars x y))
(external-function Tk_DrawFocusHighlight (tkwin gc width drawable))
(external-function Tk_DrawTextLayout (display drawable gc layout 
   x y firstChar lastChar))
(external-function Tk_Fill3DPolygon (tkwin drawable border 
   pointPtr numPoints borderWidth leftRelief))
(external-function Tk_Fill3DRectangle (tkwin drawable border x 
   y width height borderWidth relief))
(external-function Tk_FindPhoto (interp imageName))
(external-function Tk_FontId (font))
(external-function Tk_Free3DBorder (border))
(external-function Tk_FreeBitmap (display bitmap))
(external-function Tk_FreeColor (colorPtr))
(external-function Tk_FreeColormap (display colormap))
(external-function Tk_FreeCursor (display cursor))
(external-function Tk_FreeFont (Tk_Font))
(external-function Tk_FreeImage (image))
(external-function Tk_FreeOptions (specs widgRec display needFlags))
(external-function Tk_FreePixmap (specs widgrec display needflags))
(external-function Tk_FreeTextLayout ( textLayout))
(external-function Tk_FreeXId (display xid))
(external-function Tk_GCForColor (colorPtr drawable))
(external-function Tk_GeometryRequest (tkwin reqWidth reqHeight))
(external-function Tk_Get3DBorder (interp tkwin colorName))
(external-function Tk_GetAllBindings (interp bindingTable object))
(external-function Tk_GetAnchor (interp string anchorPtr))
(external-function Tk_GetAtomName (tkwin atom))
(external-function Tk_GetBinding (interp bindingTable object eventString))
(external-function Tk_GetBitmap (interp tkwin string))
(external-function Tk_GetBitmapFromData (interp tkwin source width height))
%% (external-function Tk_GetCanvasVisitor (interp name))
(external-function Tk_GetCapStyle (interp string capPtr))
(external-function Tk_GetColor (interp tkwin name))
(external-function Tk_GetGC(interp tkwin string))
(external-function Tk_GetCursor (interp tkwin string))
(external-function Tk_GetCursorFromData (interp tkwin source mask 
   width height xHot yHot fg bg))
%% (external-function Tk_GetDoublePixels (interp tkwin  string doublePtr))
(external-function Tk_GetFont (interp tkwin  string))
(external-function Tk_GetFontFromObj (interp tkwin objPtr))
(external-function Tk_GetFontMetrics (font fmPtr))
(external-function Tk_GetImage (interp tkwin name changeProc clientData))
(external-function Tk_GetImageMasterData (interp name typePtrPtr))
(external-function Tk_GetItemTypes (trA))
(external-function Tk_GetJoinStyle (interp string joinPtr))
(external-function Tk_GetJustify (interp string justifyPtr))
(external-function Tk_GetNumMainWindows (aa))
(external-function Tk_GetOption (tkwin name className))
(external-function Tk_GetPixels (interp tkwin string intPtr))
(external-function Tk_GetRelief (interp name reliefPtr))
(external-function Tk_GetRootCoords (tkwin xPtr yPtr))
(external-function Tk_GetScrollInfo (interp aargc  aargv dblPtr intPtr))
(external-function Tk_GetScreenMM (interp tkwin string doublePtr))
(external-function Tk_GetSelection (interp tkwin selection target proc clientData))
(external-function Tk_GetUid ( string))
(external-function Tk_GetVisual (interp tkwin string depthPtr colormapPtr))
(external-function Tk_GetVRootGeometry (tkwin xPtr yPtr widthPtr heightPtr))
(external-function Tk_Grab (interp tkwin grabGlobal))
(external-function Tk_HandleEvent (eventPtr))
(external-function Tk_IdToWindow (display window))
(external-function Tk_ImageChanged (master x y width height imageWidth imageHeight))
(external-function Tk_Init (interp))
(external-function Tk_InternAtom(tkwin name))
(external-function Tk_IntersectTextLayout ( layout x y width height))
%%(external-function Tk_Main (aargc aargv appInitProc))
(external-function Tk_MainLoop (l))
(external-function Tk_MaintainGeometry (slave master x y width height))
(external-function Tk_MainWindow (interp))
(external-function Tk_MakeWindowExist (tkwin))
(external-function Tk_ManageGeometry (tkwin mgrPtr clientData))
(external-function Tk_MapWindow (tkwin))
(external-function Tk_MeasureChars (tkfont source maxChars maxPixels flags lengthPtr))
(external-function Tk_MoveResizeWindow (tkwin x y width height))
(external-function Tk_MoveWindow (tkwin x y))
(external-function Tk_MoveToplevelWindow (tkwin x y))
(external-function Tk_NameOf3DBorder (border))
(external-function Tk_NameOfAnchor (anchor))
(external-function Tk_NameOfBitmap (display bitmap))
(external-function Tk_NameOfCapStyle (cap))
(external-function Tk_NameOfColor (colorPtr))
(external-function Tk_NameOfCursor (display cursor))
(external-function Tk_NameOfFont (font))
(external-function Tk_NameOfImage (imageMaster))
(external-function Tk_NameOfJoinStyle (join))
(external-function Tk_NameOfJustify (justify))
(external-function Tk_NameOfRelief (relief))
(external-function Tk_NameToWindow (interp pathName tkwin))
(external-function Tk_OwnSelection (tkwin selection proc clientData))
(external-function Tk_ParseArgv (interp tkwin aargc Ptr aargv argTable flags))
%%(external-function Tk_OrientParseProc (clientData interp tkwin  value widgRec offset))
%%(external-function Tk_OrientPrintProc ( clientData tkwin widgRec offset freeProcPtr))
(external-function Tk_PhotoPutBlock (handle blockPtr x y width height))
(external-function Tk_PhotoPutZoomedBlock ( handle blockPtr x y 
   width height zoomX zoomY subsampleX subsampleY))
(external-function Tk_PhotoGetImage (handle blockPtr))
(external-function Tk_PhotoBlank (handle))
(external-function Tk_PhotoExpand (handle width height ))
(external-function Tk_PhotoGetSize (handle widthPtr heightPtr))
(external-function Tk_PhotoSetSize (handle width height))
(external-function Tk_PointToChar (layout x y))
(external-function Tk_PostscriptBitmap (interp tkwin psInfo 
   bitmap startX startY width height))
(external-function Tk_PostscriptColor (interp psInfo colorPtr))
(external-function Tk_PostscriptFontName (tkfont dsPtr))
(external-function Tk_PostscriptFont (interp psInfo font))
(external-function Tk_PostscriptImage (image interp tkwin psinfo x y 
   width height prepass))
(external-function Tk_PostscriptPath (interp psInfo coordPtr numPoints))
(external-function Tk_PostscriptStipple (interp tkwin psInfo bitmap))
(external-function Tk_PostscriptY (y psInfo))
%%(external-function Tk_Preserve(display colormap))
(external-function Tk_QueueWindowEvent (eventPtr position))
(external-function Tk_RedrawImage (image imageX imageY width height 
   drawable drawableX drawableY))
(external-function Tk_ResizeWindow (tkwin width height))
(external-function Tk_RestackWindow (tkwin aboveBelow other))
(external-function Tk_RestrictEvents (proc arg prevArgPtr))
(external-function Tk_SafeInit (interp))
(external-function Tk_SetAppName (tkwin name))
(external-function Tk_SetBackgroundFromBorder ( tkwin border))
(external-function Tk_SetClass (tkwin className))
(external-function Tk_SetGrid (tkwin reqWidth reqHeight gridWidth gridHeight))
(external-function Tk_SetInternalBorder (tkwin width))
(external-function Tk_SetWindowBackground (tkwin pixel))
(external-function Tk_SetWindowBackgroundPixmap( tkwin pixmap))
(external-function Tk_SetWindowBorder (tkwin pixel))
(external-function Tk_SetWindowBorderWidth (tkwin width))
(external-function Tk_SetWindowBorderPixmap(tkwin pixmap))
(external-function Tk_SetWindowColormap (tkwin colormap))
(external-function Tk_SetWindowVisual (tkwin visual depth colormap))
(external-function Tk_SizeOfBitmap (display bitmap widthPtr heightPtr))
(external-function Tk_SizeOfImage (image widthPtr heightPtr))
%%(external-function Tk_StateParseProc (clientData interp tkwin value widgRec offset))
%%(external-function Tk_StatePrintProc ( clientData tkwin widgRec offset freeProcPtr))
(external-function Tk_StrictMotif (tkwin))
(external-function Tk_TextLayoutToPostscript (interp layout))
(external-function Tk_TextWidth (font string numChars))
(external-function Tk_UndefineCursor (window))
(external-function Tk_UnderlineChars (display drawable gc tkfont source x y firstChar lastChar))
(external-function Tk_UnderlineTextLayout (display drawable gc layout x y underline))
(external-function Tk_Ungrab (tkwin))
%%(external-function Tk_UnmaintainGeometry (slave master))
(external-function Tk_UnmapWindow (tkwin))
(external-function Tk_UnsetGrid (tkwin))
(external-function Tk_UpdatePointer (tkwin x y state))

%*
%* Tcl commands exported by Tk:
%*/

(external-function Tk_BellObjCmd (clientData interp objc objv))
(external-function Tk_BindCmd (clientData interp aargc  aargv))
(external-function Tk_BindtagsCmd (clientData interp aargc  aargv))
%% (external-function Tk_ButtonCmd (clientData interp aargc aargv))
(external-function Tk_CanvasObjCmd (clientData interp aargc   objv))
%%(external-function Tk_CheckbuttonCmd (clientData interp aargc  aargv))
(external-function Tk_ClipboardCmd (clientData interp aargc  aargv))
%%(external-function Tk_ChooseColorCmd (clientData interp aargc  aargv))
%%(external-function Tk_DestroyCmd (clientData interp aargc  aargv))
%%(external-function Tk_EntryCmd (clientData interp aargc  aargv))
(external-function Tk_EventObjCmd (clientData interp aargc  aargv))
%%(external-function Tk_FrameCmd (clientData interp aargc  aargv))
(external-function Tk_FocusObjCmd (clientData interp aargc   objv))
(external-function Tk_FontObjCmd (clientData interp objc objv))
%%(external-function Tk_GetOpenFileCmd (clientData interp aargc  aargv))
%%(external-function Tk_GetSaveFileCmd (clientData interp aargc  aargv))
(external-function Tk_GrabCmd (clientData interp aargc  aargv))
(external-function Tk_GridCmd (clientData interp aargc  aargv))
%%(external-function Tk_ImageCmd (clientData interp aargc  aargv))
%%(external-function Tk_LabelCmd (clientData interp aargc  aargv))
%%(external-function Tk_ListboxCmd (clientData interp aargc  aargv))
%%(external-function Tk_LowerCmd (clientData interp aargc  aargv))
%%(external-function Tk_MenuCmd (clientData interp aargc  aargv))
%%(external-function Tk_MenubuttonCmd (clientData interp aargc  aargv))
%%(external-function Tk_MessageBoxCmd (clientData interp aargc  aargv))
(external-function Tk_MessageCmd (clientData interp aargc  aargv))
%%(external-function Tk_OptionCmd (clientData interp aargc  aargv))
(external-function Tk_PackCmd (clientData interp aargc  aargv))
(external-function Tk_PlaceCmd (clientData interp aargc  aargv))
%%(external-function Tk_RadiobuttonCmd (clientData interp aargc  aargv))
%%(external-function Tk_RaiseCmd (clientData interp aargc  aargv))
%%(external-function Tk_ScaleCmd (clientData interp aargc  aargv))
(external-function Tk_ScrollbarCmd (clientData interp aargc aargv))
(external-function Tk_SelectionCmd (clientData interp aargc aargv))
(external-function Tk_SendCmd (clientData interp aargc  aargv))
(external-function Tk_TextCmd (clientData interp aargc  aargv))
(external-function Tk_TkObjCmd (clientData interp objc objv))
(external-function Tk_TkwaitCmd (clientData interp aargc  aargv))
%%(external-function Tk_ToplevelCmd (clientData interp aargc  aargv))
%%(external-function Tk_UpdateCmd (clientData interp aargc  aargv))
(external-function Tk_WinfoObjCmd (clientData interp objc objv))
(exTernal-function Tk_WmCmd (clientData interp aargc  aargv))

(external-function Tcl_Eval (interp stri))
(external-function Tcl_CreateInterp (in))
(external-function Tcl_DeleteInterp (interp))
(external-function Tcl_Init (interp))
(external-function Tcl_TraceVar (interp stri stra strb strc))
(external-function Tcl_GetVar (interp stri fla))
(external-function Tcl_SetVar (interp stri newval fla))

(on r2i)

(compiletime (input-case 'lower))
