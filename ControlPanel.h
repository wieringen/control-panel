// -----
// ControlPanel.h - Library that can be used for creating a dashboard.
// This class is implemented for use with the Arduino environment.
// Copyright (c) by Maarten Baijs, http://baijs.nl
// This work is licensed under a BSD style license.
// -----

#ifndef ControlPanel_h
#define ControlPanel_h

#include "Arduino.h"

#define MAX_PAGES 10
#define MAX_NOTES 10

// ----- Callback function types -----

extern "C" {
  typedef struct _page *Page;
  struct _page {
    char *id;
    char *name;
    void (*drawView)();
  };
}

class ControlPanel
{
public:
  // ----- Constructor -----
  ControlPanel(void);

  // ----- Set runtime parameters -----
  void newNote(char *name, char *date, char *description, void (*draw)());
  void removeNote(int noteIndex);
  void newPage(char *id, char *name, void (*draw)());
  void nextPage(void);
  void prevPage(void);
  void setCurrentPage(int index);
  void setCurrentPageIndex(int index);
  Page getPage(int index);
  Page getPageById(char *id);
  Page getCurrentPage(void);
  int getCurrentPageIndex(void);
  int getTotalPages(void);

private:
  typedef struct _note *Note;
  struct _note {
    char *title;
    char *date;
    char *description;
    int *beep;
    int *priority;
    void (*drawNote)();
  };

  Note _notes[MAX_NOTES];
  Page _pages[MAX_PAGES];
  int _pageCurrentIndex;
  int _notesTotal;
  int _pagesTotal;
};

#endif

