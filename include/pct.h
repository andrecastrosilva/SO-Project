/**
 * \defgroup pct Process Control Table (pct)
 *
 * \details
 *   The Process Control Table (\c pct) is a mapping that associates a process with a tuple of data.
 *   The process itself is identified by a unique integer value, called Process Identification (\c PID).
 *   To every process, the following data is considered:
 *   - the time at which the process arrives to the system;
 *   - an execution profile, composed of an alternate sequence of CPU- and I/O-bursts.
 *   - the state of execution, indicating the number of bursts already processed.
 *
 *   <b>It is up to the implementer to decide how to store this data</b>.
 *
 *   The interface of this module is predefined, being composed of the following functions:
 *   <table>
 *   <tr><th>function <th> function ID <th>role
 *   <tr><td>\c pctInit() <td align="center"> 201 <td> Initialize the support internal data structure
 *   <tr><td>\c pctLog() <td align="center"> 202 <td> Log the internal state of the PCT table, sorted in ascending order of PID.
 *   <tr><td>\c pctLoad() <td align="center"> 203 <td> Parse and load processes' data from file.
 *   <tr><td>\c pctGetNextBurstDuration() <td align="center"> 204 <td> Return the duration of the next process burst
 *   <tr><td>\c pctGetState() <td align="center"> 205 <td> Get the current state of a process
 *   <tr><td>\c pctSetState() <td align="center"> 206 <td> Set the state of a process
 *   </table>
 *
 *  \author Artur Pereira - 2023
 */

#ifndef __SOMM22_PCT__
#define __SOMM22_PCT__

namespace somm22
{

    /** @{ */

// ================================================================================== //

    /**
     * \brief Initialize the internal data structure
     * \details
     *  The module's internal data structure, should be initialized properly.<br>
     */
    void pctInit();

// ================================================================================== //

    /**
     * \brief Parse and load processes' data from file
     * \details
     *  The input file contains CSV-like data, representing the process behaviors 
     *  in case they run alone.
     *  Considering the lines of the input file, the following applies:
     *  - a line is a comment line, if it starts with a percent (%), with possible leading blanks (spaces or tabs);
     *  - an information line is a semi-colon separated sequence of 3 fields: pid, arrival time and burst profile;
     *  - the first field represents the PID of a process, 
     *    which must be a positive integer value;
     *  - the second field represents the arrival time of a process,
     *    which must be a non-negative integer or real value;
     *  - the third field represents the burst profile, 
     *    which is an alternate sequence of CPU- and I/O-burst, 
     *    starting and ending with a CPU-burst, 
     *    and represented by a comma separated sequence of positive integer or real values;
     *  - there can exist blanks (spaces or tabs) before or after the separators (commas or semi colons).
     *
     *  The following must be considered:
     *  - In case the input file could not be opened, 
     *    a proper error message should be sent to the standard error
     *    and the EINVAL exception should be thrown.
     *  - In case of a syntactic error in the input file, 
     *    a proper error message should be sent to the standard error
     *    and the EINVAL exception should be thrown.
     *  - In case of a semantic error (PID 0, PID repeated, even number of bursts) in the input file, 
     *    a proper error message should be sent to the standard error
     *    and the EINVAL exception should be thrown.
     */
    void pctLoad(const char* fname);

// ================================================================================== //

    /**
     * \brief Log the internal state of the process control table
     * \details
     *  The current state of the process control table (PCT) must be
     *  printed to the log stream (see logGetStream()).<br>
     *  The following must be considered:
     *  - The printing must be done in ascending order of PID
     */
    void pctLog();

// ================================================================================== //

    /**
     * \brief Get the duration of the next process burst , considering the current state of the process
     * \details
     *  The following must be considered:
     *  - 0 should be returned, if the process' state is at the end.
     *  - The \c EINVAL exception should be thrown, if an entry for the given pid does not exist.
     *  - All exceptions must be of the type defined in this project (Exception).
     *  
     * \param [in] pid PID of the process
     * \return the burst duration or 0
     */
    double pctGetNextBurstDuration(uint32_t pid);

// ================================================================================== //

    /**
     * \brief Return the current process state
     * \details
     *  The following must be considered:
     *  - The \c EINVAL exception should be thrown, if an entry for the given pid does not exist.
     *  - All exceptions must be of the type defined in this project (Exception).
     *  
     * \param [in] pid PID of the process
     * \return The process state
     */
    uint32_t pctGetState(uint32_t pid);

// ================================================================================== //

    /**
     * \brief Set the process state
     * \details
     *  The following must be considered:
     *  - The \c EINVAL exception should be thrown, if an entry for the given pid does not exist.
     *  - All exceptions must be of the type defined in this project (Exception).
     *  
     * \param [in] pid PID of the process
     * \param [in] state The process' new state
     */
    void pctSetState(uint32_t pid, uint32_t state);

// ================================================================================== //

    /** @} */

};

#endif /* __SOMM22_PCT__ */

