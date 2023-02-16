/**
 * \defgroup peq Process Event Queue (peq)
 *
 * \details 
 *   Different type of events can coexist in the queue.
 *   The Process Event Queue (\c peq) module is responsible for storing these events and
 *   allowing them to be accessed in chronological order.
 *
 *   <b>It is up to the implementer to decide which data structure to use, 
 *   as long as, at least, the following information is present</b>:
 *   - the queue of events, that must be kept sorted in ascending order of
 *     event time and, for events with the same time stamp, in order of insertion.
 *     <b>The use of a sort algorithm is not allowed</b>.
 *   - the current time, that corresponds to the time of the last event fetched.
 *
 *   The interface of this module is predefined, being composed of the following functions:
 *   <table>
 *   <tr> <th> \c function <th align="center"> function ID <th>role
 *   <tr> <td> \c peqInit() <td align="center"> 301 <td> Initialize the support internal data structure;
 *   <tr> <td> \c peqInsert() <td align="center"> 304 <td> Insert a new event in the queue;
 *   <tr> <td> \c peqLog() <td align="center"> 302 <td> Log the internal state of the process event queue.
 *   <tr> <td> \c peqIsEmpty() <td align="center"> 303 <td> Indicate if the queue is empty;
 *   <tr> <td> \c peqPeekNext() <td align="center"> 305 <td> Peek the front event;
 *   <tr> <td> \c peqFetchNext() <td align="center"> 306 <td> Fetch the front event;
 *   <tr> <td> \c peqEventTypeAsString() <td align="center"> 307 <td> Return an event type as a string
 *   </table>
 *
 *  \author Artur Pereira - 2023
 */

#ifndef __SOMM22_PEQ__
#define __SOMM22_PEQ__

namespace somm22
{

    /** @{ */

// ================================================================================== //

    /**
     * \brief Type of events
     * \ingroup peq
     * \details
     *   - Type ANY is used in the peek and pop operations to specify any type
     */
    enum EventType { 
        ARRIVAL = 0b0001,   ///< A process arrives to the system
        WAKEUP = 0b0010,    ///< A blocked process wakes up from its I/O-burst
        BLOCK = 0b0100,     ///< A running process blocks after one of its (not last) CPU-burst
        TERMINATE = 0b1000  ///< A running process terminates after its last CPU-burst
    };

// ================================================================================== //

    /**
     * \brief Process Event Queue entry
     * \details
     *   - The support register to implement the queue
     */
    struct Event 
    {
        uint32_t time;  ///< Time at which event will occur
        EventType type; ///< Type of the event
        uint32_t pid;   ///< Identification of the process
    };

// ================================================================================== //

    /**
     * \brief Initializes the internal data structure
     * \details
     *  The module's internal data structure should be initialized properly.<br>
     */
    void peqInit();

// ================================================================================== //

    /**
     * \brief Inserts an entry in queue
     * \details
     *  A new entry should be created and added to the process event queue.<br>
     *  The following must be considered:
     *  - If pid is 0, the EINVAL exception must be thrown.
     *  - If time is not in the future, the EINVAL exception must be thrown.
     *  - All exceptions must be of the type defined in this project (Exception).
     *  
     * \param [in] type The type of event to be inserted (one of ARRIVAL, POSTPONED, or TERMINATE)
     * \param [in] time Time at which event will occur
     * \param [in] pid Id of the process associated to the event
     */
    void peqInsert(EventType type, uint32_t time, uint32_t pid);

// ================================================================================== //

    /**
     * \brief Log the internal state of the process event queue
     * \details
     *  The current state of the process event queue (PEQ) must be
     *  printed to the log stream (see logGetStream()).<br>
     *  The following must be considered:
     *  - The logging must be done keeping the order of events in the queue.
     */
    void peqLog();

// ================================================================================== //

    /**
     * \brief Indicates the emptiness of the queue 
     * \return \c true if queue is empty; \c false otherwise
     */
    bool peqIsEmpty();

// ================================================================================== //

    /**
     * \brief Peek the event in the front of the queue
     * \details
     *  The event to be selected is the first in the queue, which, as said before, 
     *  is kept properly sorted.
     *  The following must be considered:
     *  - The event <b>must not be removed</b> from the queue.
     *  - The \c EINVAL exception should be thrown, if no event exists.
     *  - All exceptions must be of the type defined in this project (Exception).
     *
     * \return The front event in the queue
     */
    Event peqPeekNext();

// ================================================================================== //

    /**
     * \brief Fetch the event in the front of the queue
     * \details
     *  The event to be selected is the first in the queue, which, as said before, 
     *  is kept properly sorted.
     *  The following must be considered:
     *  - The current time must be set to the time of the event fetched.
     *  - The event <b>must be removed</b> from the queue.
     *  - The \c EINVAL exception should be thrown, if no event exists.
     *  - All exceptions must be of the type defined in this project (Exception).
     *
     * \return The front event in the queue
     */
    Event peqFetchNext();

// ================================================================================== //

    /**
     * \brief Return the given event type as a string
     *
     * \param type The event type
     * \return The event type as a string
     */
    const char *peqEventTypeAsString(EventType type);

// ================================================================================== //

    /** @} */

};

#endif /* __SOMM22_PEQ__ */

