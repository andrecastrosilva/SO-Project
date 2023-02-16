/*
 *  \author Artur Pereira <artur@ua.pt>
 */

#include "somm22.h"

#include <stdint.h>

namespace somm22
{

// ================================================================================== //

    namespace log
    {
        /* log stream, by default stdout */
        FILE *fout = stdout;

    } // end of namespace log

// ================================================================================== //

    void logOpen(FILE *fout)
    {
        soProbe(SOPROBE_GREEN, 601, "%s(...)\n", __func__);

        if (fileno(fout) == -1)
            throw Exception(errno, __func__);
        log::fout = fout;
    }

// ================================================================================== //

    void logOpen(const char *fname)
    {
        soProbe(SOPROBE_GREEN, 601, "%s(\"%s\")\n", __func__, fname);

        /* open the log file */
        FILE *fout = fopen(fname, "w");
        if (fout == NULL)
            throw Exception(errno, __func__);
        log::fout = fout;
    }

// ================================================================================== //

    void logClose()
    {
        soProbe(SOPROBE_GREEN, 602, "%s()\n", __func__);

        /* replace this comment with your code */

        fclose(log::fout);
    }

// ================================================================================== //

    void logPrint(const char *fmt, ...)
    {
        soProbe(SOPROBE_GREEN, 690, "%s(\"%s\", ...)\n", __func__, fmt);

        /* print the message */
        //fprintf(log::fout, "\e[01;34m(%03u)\e[0m ", id);
        va_list ap;
        va_start(ap, fmt);
        vfprintf(log::fout, fmt, ap);
        va_end(ap);
        fflush(log::fout);
    }

// ================================================================================== //

    FILE *logGetStream()
    {
        return log::fout;
    }

// ================================================================================== //

} // end of namespace somm22

