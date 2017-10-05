ASSIGNMENT 4: Event Driven Simulation
AUTHORS: Clayton Dembski & Floris van Rossum
USERNAMES: cjdembski & fjvanrossum
LAST UPDATED: October 5th 2017, 1:33 PM

FILES INCLUDED:
qSim.cpp
CustEvent.cpp
CustEvent.h
Event.cpp
Event.h
EventQueue.cpp
EventQueue.h
TellerEvent.cpp
TellerEvent.h
TellerList.cpp
TellerList.h
TypesOfAction.h
makefile
README.txt

HOW TO USE:
Running make all will compile the code without warnings and generate a executable
called qSim. Running qSim with compatible arguments will run the program. 
	
	./qSim #customers #tellers simulationTime averageServiceTime <seed>
	
This line will run the program. customers, tellers, simulationTime averageServiceTime
must be entered to run the program. The seed variable is optional. customers,
tellers and simulationTime should be a whole integer value while averageServiceTime
can be a value with decimals.

Running the program with the correct arguments will execute the program as defined 
by assignment 4. Improperly entering the command line arguments as specified above 
will print an error and exit the program. Assuming the program runs correctly the
program will run two simulations and print out the statistics of both simulations 
once the program is complete. When the program is complete all nodes and objects used
during runtime are properly freed and deleted. More information about how the program
runs can be found later on in the README file under PURPOSE and PROGRAM STRUCTURE &
ORGANIZATION.

DOXYGEN:


PURPOSE:
This program simulates a bank with different customers arriving over a 
random period of time and a number of tellers with a set idle time and 
random service time. It utilizes an eventqueue to determine when to execute
events and how long particular events take. At the end of the program a 
number of statistics are printed out. The program runs two different 
simulations. One where there is one queue which holds all the customers
that arrive, all the tellers pull customers from the one common queue. The other
simulation is one where each teller has it's own queue. Once customers arrive 
they choose one queue depending on its size. Customers, of course, pick the queue
with the least amount of people. Tellers pull customers from their own queue
unless the queue is empty, then they will take customers from a different queue.
The aim of the program is to find out the statistics of these two different ways
of structuring customer flow through a bank. The findings of the program 
can be found later in the README file under DISCUSSION.

PROGRAM STRUCTURE & ORGANIZATION:
The program is divided into multiple different classes. qSim.cpp holds the main() 
function which is the start of the program. qSim initializes all the necessary
objects and ensures that they are properly related. 

Event.cpp: Children: CustEvent & TellerEvent
This file holds the Event parent class which has CustEvent and TellerEvent 
as child classes. This file specifies the fields and functions that the
event class needs so that the EventQueue object can properly store both
Teller and customer events. Has a header file which allows other classes
and functions to use its functions and class definitions.

	TellerEvent.cpp:
	This file is a derived class from the Event class. It holds an action
	, the time of the event and the event queue that it is stored in.
	Additionally it contains the necessary functions to allow other
	classes to access there variables. Has a header file which allows other 
	classes and functions to use its functions and class definitions.
	
	CustEvent.cpp
	This file is a derived class from the Event class. Like TellerEvent.cpp
	it holds an action, event and event queue variable. The customer event 
	has functions that allow other classes to access its data members.
	Has a header file which allows other classes and functions to use its 
	functions and class definitions.	

EventQueue.cpp:
This file holds the information to create the event queue which holds all the events.
Uses nodes which hold an Event and two other nodes to create a sorted linked 
list of all Customer and Teller Events. The linked list is sorted based on time
of the event it holds. Each node holds links to the nodes in behind and in front of 
the node. This made it easier to sort through the node. At the base of the linked list
is a rootNode with a negative time which is cannot be retrieved from the event queue.
It is used to be able to access the data structure in an easier manner. 
Uses the generic Event class to be able to store both Teller and Customer events. 
At the beginning of the program the entire Event Queue is filled with customer arrival events
which are randomly distributed between time 0 and the simulationTime. 
Throughout the program execution events are added and removed from the event
queue. EventQueue.cpp contains all the necessary function implementations 
to handle the event queue and pass the necessary information to other classes.
Has a header file which allows other classes and functions to use its functions
and class definitions.

TellerList.cpp:
This file holds the information necessary to create a teller queue for the
simulation. Based on what simulation is run there can be multiple teller queues
or a single teller queue. The teller list is a list that holds all the teller 
queues. The 0th teller queue is one that is purely for organizational purposes.
It is not directly tied to a single teller but all tellers retrieve from it
in Simulation 1. In simulation 2 each individual teller queue stored in the 
teller list extracts customers from this teller queue. Like in EventQueue.cpp
each teller queue is made up of a node that acts as a root node. Additional 
customers will get attached onto that rootnode, in the case where there are
multiple teller queues the customer will get attached to a random rootNode. 
Because the order of the teller queue is not as important of the event queue
the node only contains a reference to the previous event in the teller queue.
Remember that events only have to be sorted based on the time that they were 
inserted into the queue and it is impossible to get an event that has to be
inserted before another event in the teller queue since the event queue handles
the correct timing of all events. All teller queues, if there are multiple, are
stored in a simple list. With a number a specific teller queue can be selected.
TellerList a header file which allows other classes and functions to use its 
functions and class definitions. At the end of the program additional work has 
to be done to ensure that each of the teller queues inside the list is properly
destructed. 

qSim.cpp:
The main loop of the program. This file contains one function main(). It will
process the command line arguments and respond accordingly by calling all 
necessary constructors and functions throughout the program. It uses all of the 
above described files to ensure that the simulation runs effectively. 

Initially it uses for loops to create all the Customer events and initialize
the teller lists. The customer arrival times and teller idle times are
randomized as described in the homework assignment. Then a while loop
handles the events in the event queue one by one until all customer events
have been processed. Once all customer events and there are no customers left
in the bank simulation 1 is done, so necessary calculations for statistics are
performed and the statistics are printed. Simulation 2 runs exactly the same except
that there are multiple teller queues defined. The while loop will run again until all
customers have left the bank and then the statistics for simulation 2 will be 
printed. At the end of the program all used objects are destructed properly.

Representation of Tellers, Customers and Events:
Teller and customer objects do not directly exist. There are only Teller and Customer
Events and TellerLists which is a list of Teller queues. Therefore you can imagine a 
TellerQueue to be a teller, as it stores customers and creates TellerEvents which are
stored in the event queue. The teller can create two kinds of TellerEvents teller idle
(TellIdle) and teller getting a customer (TellGetCust). These events can be added either
to the eventqueue or a teller queue. A customer can be seen as an event that occurs
since there is no customer class. Initially the customer arrives and is placed at a
random point in the event queue. There are two other customer events, namely customer
service (CustService) and customer leave (CustLeave) which represent a customer being serviced
by a teller and a customer leaving the bank. All of the customer events are added to the event
queue or to the teller queue. Events are represented as Customer Events (CustEvent) and
teller events (TellerEvent). Each of them are a child/derived class of Event.cpp so that
they can be stored in a common event queue and for code reuse and clarity reasons.

Algorithm explanation:
???

DISCUSSION:
Common queuing vs. per-teller queuing:
???

PROGRAM FLOW:
1. main() is run, it stores all user input and verifies that it is correct
2. Prints all user input for troubleshooting and clarity reasons
3. Customers and Tellers are initialized with a random arrival time and idle time
4. 

LOOP INVARIANTS:

PROBLEMS:

TEST CASES:

SOURCES:
1. http://en.cppreference.com/w/cpp/language/abstract_class
2. https://www.git-tower.com/learn/git/faq/change-author-name-email
3. http://www.cplusplus.com/doc/tutorial/typecasting/
4. http://www.cplusplus.com/reference/cstdlib/rand/
5. https://stackoverflow.com/questions/3001336/c-delete-a-struct
6. https://www.tutorialspoint.com/c_standard_library/c_function_strtol.htm
7. https://stackoverflow.com/questions/120876/what-are-the-rules-for-calling-the-superclass-constructor
8. https://en.wikipedia.org/wiki/Circular_dependency#Example_of_circular_dependencies_in_C.2B.2B
9. https://stackoverflow.com/questions/71959/one-file-doesnt-recognize-other-files-class-in-c
10. https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.cbclx01/overload_member_fn_base_derived.htm
11. https://stackoverflow.com/questions/2574276/java-how-can-a-constructor-return-a-value
12. https://canvas.wpi.edu/courses/4966/files/folder/Class%20Slides?preview=740902
13. https://canvas.wpi.edu/courses/4966/files/folder/Class%20Slides?preview=725194

















