// Algorithm Analysis and Big O Notation

/*
Algorithm Analysis:
    - Algorithm = A finite sequence of well definied instructions to solve a specific problem.
    - This definition sounds really similar to what a program is, what is the difference between a program and an algorithm?
    - Program = A set of instructions to perform in a particular action.

    - Algorithm (Apriori Analysis):
        - Algorithm Design = In the software design life-cycle there are 2 major steps: 1) design phase, and 2) the
            implementation phase. Algortihm design occurs in the design phase of SDLC. We design the algortihm first so that we
            know what we're going to implement in terms of software. Who designs the algorithms? It can be anyone, but generally
            it is done by someone who has domain knowledge. Generally they will work with the programmers in order to actually
            implement the algorithms. Sometimes a programmer can have the domain knowledge and can create the algorithm and
            program the algorithm itself as well.

        - Who?: People who have the domain knowledge. This can be programmers.

        - What Language?: Algorithm Design / Algortihm Analysis does not depend on a specific language. It is language independent.
            Generally the algorithm design will be written in math.

        - What Environment?: Algorithm Design / Algorithm Analysis does not depend on the hardware / operating system.

        - How?: We need to analyze how well the algorithm performs? We need to look at the Time and Space complexity.

    - Program (Posteriori Testing):
        - Program Implementation: In SDLC the program fits in the Implementation phase. Taking from the algortihm analysis /
            algorithm design, it is time to actually write the algorithm in a chosen programming language.

        - Who?: The programmers are the ones who will implement the algorithm solution.

        - What Language?: This is language dependent! We will choose what programming language will fit the best.
            C / C++, Python, Java ... etc

        - What Environment?: The environment matters in this case. The programmer needs to pay attention on what the software will
            be deployed on. Linux, Windows? Compiled / JVM? Hosted on a Web Service? 

        - How? After writing the program, we need to check to see if the algorithm is implemented properly. We will test the
            algorithm.

Characteristics Of An Algorithm:
    - Inputs:
        - Algorithms take 0 or more inputs. 

    - Output:
        - Algorithms must generate at least a single result. This return doesn't need to be a "result", but the algorithm must
            have generated some change in terms of a result.

    - Difinitiveness:
        - The algorithm must be definied, it cannot be ambiguous. It cannot be a problem that cannot be solved. This depeneds on
            the exact problem we're trying to solve: sqrt(-1)? This doesn't have a real solution, but it does have a complex
            solution. What will the algorithm try to achieve? Divide by 0, are we trying to take limits? This depends on the
            domain knowledge, and what we're trying to achieve with the algorithm. tan(x) is undefinied at certain values.

    - Finiteness:
        - the algorithm must terminate and produce a certain "result" at some point. What about programs that run continously?
            Those types of programs like Databases or Web Servers, are generally refered to as a "service" instead of as an algorithm

    - Effectiveness:
        - The steps in the algorithm must serve some purpose in solving that algorithm.
        - No unnecessary steps.
        - Are the steps we're performing the most efficient? Is our algorithm the best? Did we create a "good" algorithm?

Creating an Algorithm:
    - Swap 2 elements:

        void swap(int &x, int &y) {
            int temp = x;
            x = y;
            y = temp;
        }

Analysis Of An Algorithm:
    - How do we analyze an algorithm?
    - Time Analysis:
        - How long does it take to solve the problem with the algorithm?

    - Space Analysis:
        - When we convert the algorithm into a program, we need to pay attention to how much space / resources the algorithm
            consumes when solving the problem.

    - Network Consumption:
        - How much data does the algorithm require? Where is the data coming from? Where is the data going?

Time Complexity Analysis:
    - We will take that each statement in the algorithm takes 1 unit of time.

        void swap(int &x, int &y) {
            int temp = y;
            x = y;
            y = temp;
        }

    - Here in this example, we have 3 steps. Each of these steps takes 1 unit of time, so in total this algorithm takes 3 units
        of time.
    - The Time Function is f_t(n) = 3
        - This is constant for this algorithm.
    
    - Generally the function call itself, and the argument passing in are not considered part of the algorithm analysis.
    - Regardless of how lengthy a single statement is within the algorithm, we will still consider it to take 1 unit of time.
    - Complex statements in time analysis will be considered to take 1 unit of time.

        x = (5*3) + (7*9);

    - Here in terms of programming statements we have 2 multiplication statements, 1 addition statement, and 1 assignment
        statement. In termf of time analysis, this entire statement will be considered to take 1 unit of time. If we needed to
        further analyze the algorithm at a deeper level, then analyzing statments like this and taking into account each step
        being equal to 1 unit of time, then we can choose to do so.

Space Complexity Analysis:
    - For space complexity, we will need to analyze how many variables there are.
    - How many variables take up space on the stack? How many on the Heap?
    - What about function calls on the stack?
    - Are we going to analyze how big the stack is getting? How big the heap is getting?

    - In the swap() example, the sapce complexity is:
        - x takes up 1 unit of space
        - y takes up 1 unit of space
        - temp takes up 1 unit of space

        - total is 3 units of space is taken in this algorithm from a space complexity analysis.

    - If we need to further extend the space complexity analysis, we can look into the function call itself on the stack.
        Especially for recursive algorithms, it might be important to look at the function calls on the stack / stack unwinding.
*/


#include <iostream>


int main() {

    return 0;
}
