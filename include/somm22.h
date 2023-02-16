/**
 *  \mainpage SO+FSO group work, academic year 2022-2023, appeal season
 *
 *  \brief Simulating a FCFS processor scheduler
 *    
 *  \author Artur Pereira - 2022-2023
 *
 *  \details
 *    The purpose of this project is to implement a simulation system that simulates the activity
 *    of an FCFS processor scheduler, assuming memory is limitless and there is a single processors
 *    Every process is considered to be composed of a sequence of CPU- and I/O-bursts, 
 *    whose profiles are given by a CSV-like input file.
 *
 *    The system is composed of 5 modules:
 *    - \c pct, which holds information about the processes being simulated
 *    - \c peq, which deals with the events that command the simulation
 *    - \c log, which provides a logging mechanism
 *    - \c probing, which provides a probing mechanism
 *    - \c exception, to deal with exceptions
 * 
 * The simulation must show how the scheduling takes place.
 *
 * Only modules \c pct and \c peq are to be developed in this assignment.
 */

#ifndef __SOMM22__
#define __SOMM22__

/** \defgroup somm22 somm22 Project
 *  \brief 
 *    Umbrella for all somm22 modules
 *
 * \defgroup pct Process Control Table (pct)
 * \ingroup somm22
 * \brief 
 *   The <b>Process Control Table (pct)</b> module holds information about
 *   the processes being simulated.
 *
 * \defgroup peq Process Event Queue (peq)
 * \ingroup somm22
 * \brief 
 *   The <b>Process Event Queue (peq)</b> module deals with the events that 
 *   command the simulation.
 *
 * \defgroup log Logging 
 * \ingroup somm22
 * \brief
 *   The <b>Logging</b> module provides means to log information
 *
 * \defgroup probing Probing
 * \ingroup somm22
 * \brief
 *   The <b>Probing toolkit</b> module provides a way to print probing
 *   messages that can be turned on/off
 *
 * \defgroup exception Exception 
 * \ingroup somm22
 * \brief 
 *   The <b>Exception</b> module provides a way to avoid defensive programming
 *   in the other components of the whole somm22 system.
 *
 */

#include "dbc.h"
#include "exception.h"
#include "probing.h"
#include "log.h"
#include "pct.h"
#include "peq.h"

#endif /* __SOMM22__ */
