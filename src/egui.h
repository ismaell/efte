/*    egui.h
 *
 *    Copyright (c) 2008, eFTE SF Group (see AUTHORS file)
 *    Copyright (c) 1994-1996, Marko Macek
 *
 *    You may distribute under the terms of either the GNU General Public
 *    License or the Artistic License, as specified in the README file.
 *
 */

#ifndef __EGUI_H__
#define __EGUI_H__

#include "gui.h"
#include "c_bind.h"  // KeySel

void SetBranchCondition(int cond);

class EEventMap;
class EKeyMap;
class GxView;
class ExState;
class EView;

class EFrame: public GFrame {
public:
    EEventMap *CMap;
    EModel *CModel;

    EFrame(int XSize, int YSize);
    virtual ~EFrame();

    virtual void Update();
    virtual void UpdateMenu();
};

class EGUI: public GUI {
public:
    EKeyMap *ActiveMap;
    EKeyMap *OverrideMap;
    char CharMap[32];

    EGUI(int &argc, char **argv, int XSize, int YSize);
    virtual ~EGUI();

    virtual int ExecCommand(GxView *view, int Command, ExState &State);
    virtual int ExecMacro(GxView *view, int Macro);
    virtual int ExecMacro(GxView *view, const char *name);
    virtual int BeginMacro(GxView *view);

    void SetMsg(char *Msg);
    void SetOverrideMap(EKeyMap *aMap, char *ModeName);
    void SetMap(EKeyMap *aMap, KeySel *ks);
//    void CharEvent(TEvent &Event, char Ch);

    void DispatchKey(GxView *view, TEvent &Event);
    void DispatchCommand(GxView *view, TEvent &Event);

    virtual void DispatchEvent(GFrame *frame, GView *view, TEvent &Event);

    // Stack related
    int Plus();
    int Minus();
    int Mul();
    int Div();
    int Random();
    int Time();
    int Ms();

    int And();
    int Or();
    int Xor();
    int Shift();

    int Equals();
    int Less();
    int Flag();
    int Abort();

    int Dup();
    int Drop();
    int Swap();
    int Over();
    int Rot();

    int ToR();
    int RFrom();
    int RFetch();
    int I();
    int J();

    int Diag(ExState &State);
    int Execute(ExState &State, GxView *view);
    int ExecuteCommand(ExState &State, GxView *view);

    int FileCloseX(EView *View, int CreateNew, int XClose = 0);
    int FileClose(EView *View, ExState &State);
    int FileCloseAll(EView *View, ExState &State);

    int WinNext(GxView *view);
    int WinPrev(GxView *view);

    int WinHSplit(GxView *View);
    int WinClose(GxView *View);
    int WinZoom(GxView *View);
    int WinResize(ExState &State, GxView *View);
    int ExitEditor(EView *View);

    int FrameNew();
    int FrameClose(GxView *View);
    int FrameNext(GxView *View);
    int FramePrev(GxView *View);

    int ShowEntryScreen();
    int RunProgram(ExState &State, GxView *view);
    int RunProgramAsync(ExState &State, GxView *view);

    int MainMenu(ExState &State, GxView *View);
    int ShowMenu(ExState &State, GxView *View);
    int LocalMenu(GxView *View);

    int DesktopSaveAs(ExState &State, GxView *View);
    int DesktopLoad(ExState &State, GxView *View);

    int findDesktop(char *argv[]);
    void DoLoadDesktopOnEntry(int &argc, char **argv);
    void EditorInit();
    int CmdLoadFiles(int &argc, char **argv);
    int InterfaceInit(int &argc, char **argv);
    void DoLoadHistoryOnEntry(int &argc, char **argv);
    void DoSaveHistoryOnExit();

    void EditorCleanup();
    void InterfaceCleanup();

    virtual int Start(int &argc, char **argv);
    virtual void Stop();
};

#endif
