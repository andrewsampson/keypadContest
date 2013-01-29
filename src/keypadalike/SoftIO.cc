/*
This program allows limited support to compile and run programs written for
the Atmel ATTiny2313 to work like they were in a Hall Research KP2B keypad,
only compiled for a native desktop environment with a Qt GUI instead of
hardware buttons and LEDs.

    Copyright (C) Copyright 2012 David Fries.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "SoftIO.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

SoftIO::SoftIO()
{
	QVBoxLayout *vlayout=new QVBoxLayout;
	QHBoxLayout *hlayout=new QHBoxLayout;
	for(int i=0; i<BUTTON_COUNT; ++i)
	{
		if(i==BUTTON_COUNT/2)
		{
			vlayout->addLayout(hlayout);
			hlayout=new QHBoxLayout;
		}
		Buttons[i]=new QPushButton(QString("%1").arg(i));
		hlayout->addWidget(Buttons[i]);
	}
	vlayout->addLayout(hlayout);
	setLayout(vlayout);
}
