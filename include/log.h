/**
 * \defgroup log Logging 
 *
 * \details
 *
 *   The interface of this module is predefined, being composed of the following functions:
 *   <table>
 *   <tr> <th> \c function <th align="center"> function ID <th>role
 *   <tr> <td> \c logOpen() <td align="center"> 601 <td> Sets the log stream or log file
 *   <tr> <td> \c logClose() <td align="center"> 602 <td> Closes the log stream
 *   <tr> <td> \c logGetStream() <td align="center"> --- <td> Return the current log stream
 *   <tr> <td> \c logPrint() <td align="center"> 690 <td> Log function equivalent to the \c printf function 
 *   </table>
 *
 *  \author Artur Pereira - 2022-2023
 */

#ifndef __SOMM22_LOG__
#define __SOMM22_LOG__

#include <stdio.h>

namespace somm22
{

    /** @{ */

    /**
     * \brief Set log stream
     * \details The given stream will be used to store logging information
     * \param [in] fout stream where logging must be written to
     */
    void logOpen(FILE *fout);

    /**
     * \brief Open log file
     * \details The given file will be used to store logging information
     * \param [in] fname Path to file where logging must be written to
     */
    void logOpen(const char *fname);

    /**
     * \brief Close log stream
     */
    void logClose();

    /**
     * \brief Return the current log stream
     * \return The current log stream
     */
    FILE *logGetStream();

    /**
     *  \brief Print a log message
     *  \details
     *   This function work like the \c printf function but send the output to the
     *   current log stream
     *
     *  \param [in] fmt the format string (as in \e printf)
     */
    void logPrint(const char *fmt, ...);

    /** @} */

};

#endif /* __SOMM22_LOG__ */

