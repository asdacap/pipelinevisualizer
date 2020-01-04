What is this?
=============

I made this back in 2011. Github was just starting to get popular back then, so I don't think I knew of its existence. 
9 years later, I figure it would be cool to get all my old pet project into Github. Now that I look back I wonder, where
did I get the time to make this?

Some thoughts
-------------

Back then I was wondering what does the .dll files are for? From MidiMania, which was a separate project, I learned
that it is possible to dynamically load modules and make plugins, and so this project was made that way also, where
the signal processors were contained in several dynamically loaded library, creating plugins, with the help of 
Qt's plugin system. 

I also just learned of the existence of GNU/Linux. I always wanted to make GUI program, as CLI just dont appeal to me.
I don't know how to code HTML back then. C# support was not brilliant in Linux, Gtk was confusing to me and hard to make
cross platform, so I use Qt, which was relatively easier. This project was made originally with Qt Creator, and qmake, 
which was Qt's build system before cmake. I thought I've converted it to cmake, but it turns out it was not completed,
or I could not find the code where it was completed. So I have to fix it and modify some stuff to make it work now along
with some compatibility fix for newer version of Qwt. It is buildable now.  

This is also the first project I made where I started learning and using vim bindings. Ah, how time flies. I missed the
energy and drive.

---

Hi! This is the README for PipelineVisualizer version 0.2
=========================================================

What is PipelineVisualizer?
---------------------------

PipelineVisualizer is a set of library and a program based on Qt that is basically, a dinamic signal processor in which the calculation can be changed by the mean of visual pipeline drag and drop ui.


Support
-------

All the documentation for using, understanding and extending PipelineVisualizer can be found at it's wiki, that is at http://sourceforge.net/apps/mediawiki/pipelinevisual/


New For 0.2 from 0.1.3
----------------------

- Semi Transparent line colour for unselected SP(Signal Processor), so it would not look too messy.
- The list of SP is now sortable and searchable but must be doubleclicked to add SP.
- A new Template feature that enable a creation of some SPs based on a Pipeline.
- Some menu has been reorganize.
- Whole new SP
  - BooleanAnd
  - BooleanOr
  - BooleanXor
  - DoubleDivide
  - DoubleInverse
  - DoubleMinus
  - DoublePlus
  - IntegerDivide.
  - DoubleIsEqual
  - DoubleIsGreatorThan
  - DoubleIsLessThan
  - SignalMultiply
  - SignalDivide
  - SignalInverse
  - SignalPlus
  - SignalMinus
  - SignalDifferentiation
  - SignalIntegration
  - SignalDeviation
  - SignalSum
  - SignalSquareRoot
  - DoubleSquareRoot
  - SignalMedian
- And other fixes that go in the background.
0.2.1 Minor Fix--> Now include the two dependent dll (mingwm10.dll and libgcc_s_dw2-1.dll) and removed the *.a files which is not needed.

