// -----
// ControlPanel.cpp - Library that can be used for creating a dashboard.
// This class is implemented for use with the Arduino environment.
// Copyright (c) by Maarten Baijs, http://baijs.nl
// This work is licensed under a BSD style license.
// -----

#include "ControlPanel.h"

ControlPanel::ControlPanel(void) {
  _pagesTotal = 0;
  _pageCurrentIndex = 0;
} // ControlPanel

void ControlPanel::newPage(char *id, char *name, void (*draw)()) {
  Page newPage = (Page) malloc(sizeof(struct _page));

  newPage->id = id;
  newPage->name = name;
  newPage->drawView = draw;

  _pages[_pagesTotal] = newPage;
  _pagesTotal += 1;
}

void ControlPanel::nextPage(void) {
  ControlPanel::setCurrentPageIndex(ControlPanel::getCurrentPageIndex() + 1);
}

void ControlPanel::prevPage(void) {
  ControlPanel::setCurrentPageIndex(ControlPanel::getCurrentPageIndex() - 1);
}

Page ControlPanel::getPage(int index) {
  return _pages[index];
}

int ControlPanel::getCurrentPageIndex(void) {
  return _pageCurrentIndex;
}

int ControlPanel::getTotalPages(void) {
  return _pagesTotal;
}

Page ControlPanel::getPageById(char *id) {
  int i = 0;

  for(i = 0; i < ControlPanel::getTotalPages(); i++) {
    if (ControlPanel::getPage(i)->id == id) {
      return ControlPanel::getPage(i);
    }
  }
}

Page ControlPanel::getCurrentPage(void) {
  return ControlPanel::getPage(ControlPanel::getCurrentPageIndex());
}

void ControlPanel::setCurrentPageIndex(int index) {
  if( index > 0 && index < ControlPanel::getTotalPages() - 1) {
    _pageCurrentIndex = index;
  }
}

void ControlPanel::setCurrentPage(Page page) {
    ControlPanel::setCurrentPageIndex(index);
}

void ControlPanel::newNote(char *name, char *date, char *description, void (*draw)()) {

}

void ControlPanel::removeNote(int noteIndex) {

}

void ControlPanel::getNotesByPriority(int priority) {
  int i = 0;

  for(i = 0; i < ControlPanel::getTotalNotes(); i++) {
    if (ControlPanel::getNote(i)->priority == 1) {
      return ControlPanel::getNote(i);
    }
  }
}
