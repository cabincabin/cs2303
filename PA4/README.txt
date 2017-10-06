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
runs can be found later on in the README file under PURPOSE and PROGRAM STRUCTURE & ORGANIZATION.

DOXYGEN:
Doxygen comments were used in this assignment. Entering the command “make docs” in 
the PA4_cjdembski_fjvanrossum assignment will generate the proper doxygen documentation.
In the folder html there is a file called “index.html” opening this with a compatible browser
 such as firefox will produce the webpage with the documentation to our program.

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

Explain how you represented tellers events and customers:
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

ALGORITHM EXPLANATION  AND DISCUSSION:
See: Test Cases

For each of the test cases, one can see that the maximum wait time for each of the test cases 
with many customers is much greater in Simulation 2, each teller having their own queue. 
This is especially seen as the number of tellers increase in numbers, as for the second section
of test cases. Because in the second simulation the line that the Teller chooses from when their
own line is empty is indiscriminate, this means that a single line can be ignored by all other
tellers but the teller who owns a line, while a different single line may have all its customers
pulled from it by a great number of customers. Even though, if one were to look at each line,
the number of customers in each line would be roughly the same for large amounts of customers,
this does not show the speed of each line: one may be a crawl while the other quickly 
drains and is filled again. This also explains the miniscule difference in the average
time spent in the bank, as the few customers who are in the bank longer pull up the 
wait times. In this way, a single queue is far superior to multiple queues. This effect
is shown more clearly by having more customers, having less tellers, and having smaller
hours open.

The effect of the queue systems, however, is just the opposite when there are many 
tellers and only a few customers. Although the difference is small, the max time 
spent in the bank and the max wait time are ever so slightly less. This is as all
the customers get distributed evenly to each teller, they almost never have to
wait in line behind another person. In addition, if the teller they are in line
for idles for a long time, another teller can grab them, thereby mitigating the
wait time both by other customers and the tellers themselves. In this way, 
multiple queues are slightly superior. This effect is shown more clearly by 
increasing the tellers, decreasing the customers and increasing the hours open 
however, if the numbers are increased too high, this model slowly converges with
the single queue in terms of efficiency, and, therefore, neither are more efficient. 
 
One important thing to note is that the standard deviation is similar between both
simulations inside a test case. Standard deviation can be described as the average
deviation of the customer wait time from the average. Because the standard deviation
is the same for both of the simulations it means that the spread of the wait times 
as compared to the average between the two simulations is similar. This standard 
deviation can be tied in to the maximum wait time which seemed to be higher for 
simulation 2: multiple teller queues.


One thing, however, that is obvious from running each simulation is that the 
computational energy and time required to generate the second Simulation is 
much greater than the first. This is obvious for two parts of the teller queuing 
system. In the first simulation, by only having one queue to get customers for 
the tellers from, the tellers only have to look at 1 place, reducing the number 
of computations by the number of tellers for each time the teller is called. 
Second, the customers only have to choose 1 place to arrive at, reducing the 
number of choice again by the number of tellers.

In the Second Simulation, the problem is slightly different. For each customer, 
when a customer enters, they must look through every single possible teller and 
find the shortest line. They must then find and gather a list of every teller that 
has this shortest list. At this point, they have looked through every teller twice. 
Finally, they must choose a random teller to go to in line. When a teller is able 
to serve a customer, if their given line is empty, they must take an approach much 
the same as the customer: look through every teller line and find all of the ones
that have customers, assemble these tellers into a list, choose a random teller
and take out the first customer in this line. This innate inefficiency causes runtimes 
with large customers to be much larger than its simulation counterpart. 

PROGRAM FLOW: 
1. main() is run, it stores all user input and verifies that it is correct
2. Prints all user input for troubleshooting and clarity reasons
3. Customers and Tellers are initialized with a random arrival time and idle time
4. Based on the distribution of customers in eventqueue a while loop is entered
5. Retrieves first event from the event queue based on time
6. Based on the action type of the event the program will call different functions to 
handle the event. Typically an event will go from a customer arrival to a get customer 
teller event to a customer service event to a customer leave event. Additionally there 
are teller idle event whenever a teller is not servicing a customer.
7. Steps 5 and 6 are repeated until all customers have left the bank, this means 
there are no more customer events in the event queue and there are no customers 
in the teller queues.
8. Tellers will idle until the end of the day which is defined by the user at the 
beginning of the program.
9. When the end of the day is reached the program prints out all the statistics of 
the simulation
10. Parts 4 through 9 are repeated for simulation 2 which uses multiple teller 
queues. Of course the initialization of the teller queues is different since 
there are multiple teller queues in TellerList instead of one.

LOOP INVARIANTS: 
Although loop invariants are not required in the assignment 4 document 
we decided to include them because it enhanced the clarity and 
readability of our code.

qSim.cpp:
int main(int argc, char ** argv)
	// Pre-condition: customers is a non-zero user specified number
	for(int i = 0; i < customers; i++)
		// LOOP-INVARIANT: There are now i number of CustEvents in EventQueue
	// Pre-condition: tellers is a non-zero user specified number
	for(int i = 0; i < tellers; i++)
		// LOOP-INVARIANT: TellerEvent is initialized with a random idle time
		// and inserted in TellerList
	// Pre-condition: TellerEvent teller has been initialized
	// and all teller objects have been initialized with
	// a random idle time.
	for(int i = 0; i < tellers; i++)
		// LOOP-INVARIANT: idleTime is equal to the idle time of i Tellers
		// together
	// Pre-condition: There are customers in the bank (event queue or tellerlists)
	while(Tell -> GetPeopleInBank()!=0 || queue->EventQueueCusts()!=0)
		// LOOP-INVARIANT: An event from the event queue has been processed and 
the nextEv object has been deleted
	// Pre-condition: All customers have been handled in the bank
	for(int i = 0; i < customers; i++)
		// LOOP-INVARIANT: i is less than the number of customers
	// Pre-condition: Queue has been initialized and customers is a
	// user specified non-zero number
	for(int i = 0; i < customers; i++)
	// LOOP-INVARIANT: A customer object has been initialized with a random
// arrival time
// Pre-condition: Queue has been initialized and tellers is a
// user specified non-zero number
for(int i = 0; i < tellers; i++)
	// LOOP-INVARIANT: A teller event has been created with a random idle
	// time
// Pre-condition: Tellers have been initialized with a random
	// idle time
for(int i = 0; i < tellers; i++)
// Loop-invariant: IdleTime is now the sum idle time of all
		// previously called tellers' idle time
// Pre-condition: There are customers in the bank (event queue or tellerlists)
	while(Tell -> GetPeopleInBank()!=0 || queue->EventQueueCusts()!=0)
		// Pre-condition: All teller queues have been initialized
		for(i = 1; i <= Tell -> getListLen(); i++) 
			// LOOP-INVARIANT: The length of the teller queue Tell has
			// been checked
		// Pre-condition: The variable lineS is a real number and
		// all teller queues have been initialized
		for(i = 1; i <= Tell -> getListLen(); i++)
			// LOOP-INVARIANT: The teller Tell's queue length has been checked, 
minimum size 	has been found
	// Pre-condition: All customers have gone through the bank and been serviced
	for(int i = 0; i < customers; i++)
		// LOOP-INVARIANT: i is less than the number of customers
	
TEST CASES: 

MANY CUSTOMERS & FEW TELLERS
There are two test cases because we wanted to show the 
randomness of the results. The following two test cases 
are run with different commands.
TEST CASE 1:

--------Simulation 1--------
Customers Served: 10000
Time Required to Serve All Customers: 207.678 min
Tellers: 100
Queuing System: Single Queue
Average Time Spent in Bank: 45.3521 min
Standard Deviation: 23.4342 min
Max Wait Time: 83.8463 min
Teller Service Time: 20105.2 min
Teller Idle Time: 890.165 min
--------Simulation 2--------
Customers Served: 10000
Time Required to Serve All Customers: 206.492 min
Tellers: 100
Queuing System: Multiple Queues
Average Time Spent in Bank: 45.4247min
Standard Deviation: 23.5443min
Max Wait Time: 90.8138min
Teller Service Time: 19935.3 min
Teller Idle Time: 987.519min

TEST CASE 2
--------Simulation 1--------
Customers Served: 20000
Time Required to Serve All Customers: 806.498 min
Tellers: 50
Queuing System: Single Queue
Average Time Spent in Bank: 376.919 min
Standard Deviation: 213.634 min
Max Wait Time: 743.23 min
Teller Service Time: 40011.2 min
Teller Idle Time: 460.227 min
--------Simulation 2--------
Customers Served: 20000
Time Required to Serve All Customers: 806.564 min
Tellers: 50
Queuing System: Multiple Queues
Average Time Spent in Bank: 375.925min
Standard Deviation: 213.5min
Max Wait Time: 745.008min
Teller Service Time: 39994.9 min
Teller Idle Time: 459.873min

MANY TELLERS & MANY CUSTOMERS
We only ran one of these giant test cases because it took an 
incredibly long time to run the test.
TEST CASE 1:
--------Simulation 1--------
Customers Served: 10000
Time Required to Serve All Customers: 63.8176 min
Tellers: 1000
Queuing System: Single Queue
Average Time Spent in Bank: 2.02652 min
Standard Deviation: 1.15216 min
Max Wait Time: 0.354397 min
Teller Service Time: 20093.2 min
Teller Idle Time: 46104.9 min
--------Simulation 2--------
Customers Served: 10000
Time Required to Serve All Customers: 63.7444 min
Tellers: 1000
Queuing System: Multiple Queues
Average Time Spent in Bank: 2.02707min
Standard Deviation: 1.15262min
Max Wait Time: 1.51497min
Teller Service Time: 20113.5 min
Teller Idle Time: 45903.7min

FEW CUSTOMERS & MANY TELLERS
This test case is for a scenario where there are few customers but many 
tellers, two test cases were run with different command line arguments for each.
TEST CASE 1:
--------Simulation 1--------
Customers Served: 100
Time Required to Serve All Customers: 13.6825 min
Tellers: 500
Queuing System: Single Queue
Average Time Spent in Bank: 1.91106 min
Standard Deviation: 1.16402 min
Max Wait Time: 0.033263 min
Teller Service Time: 190.678 min
Teller Idle Time: 7697.97 min
--------Simulation 2--------
Customers Served: 100
Time Required to Serve All Customers: 13.2505 min
Tellers: 500
Queuing System: Multiple Queues
Average Time Spent in Bank: 1.98636min
Standard Deviation: 1.17844min
Max Wait Time: 0.0149363min
Teller Service Time: 198.305 min
Teller Idle Time: 7426.23min

TEST CASE  2:
--------Simulation 1--------
Customers Served: 100
Time Required to Serve All Customers: 13.1658 min
Tellers: 500
Queuing System: Single Queue
Average Time Spent in Bank: 2.13644 min
Standard Deviation: 1.17109 min
Max Wait Time: 0.0214384 min
Teller Service Time: 213.121 min
Teller Idle Time: 7369.52 min
--------Simulation 2--------
Customers Served: 100
Time Required to Serve All Customers: 13.5751 min
Tellers: 500
Queuing System: Multiple Queues
Average Time Spent in Bank: 2.12683min
Standard Deviation: 1.18663min
Max Wait Time: 0.0210475min
Teller Service Time: 212.153 min
Teller Idle Time: 7597.55min


PROBLEMS HAD:
One of the first problems we ran into while creating this code was type mismatching 
between how the EventQueue system worked and how each Event worked. Due to a 
miscommunication, there  was a distinct mixing, greater than the amount seen currently, 
of references and pointers. Because of this, the program ran into problems due to type mismatch.
Most of the problems we ran into, however, was due to permissions and circular definitions 
of classes. The EventQueue had to be initiated with an Event, yet each Event was to 
contain an event Queue. In the header file, we struggled with Pre-definitions to allow 
for compile time permissions. Eventually, we had to change the compilers for each system 
so that they did not need to initialize the element of the other class until both were created. 

Another problem we encountered was interpreting the code the other partner 
wrote. This is because the c++ syntax can be incredibly hard to understand. 
Initially we did not use proper commenting of the work we had done. If one partner 
worked on it for a couple of hours the other would have to spend a similar amount of 
time trying to decipher the code the other partner wrote. This resulted in a lot of 
wasted time. We fixed the problem with better commenting, however in the future we 
have to ensure that any code that is written is properly commented.

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









