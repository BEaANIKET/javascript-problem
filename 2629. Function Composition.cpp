/**
 * @param {Function[]} functions
 * @return {Function}
 */


/*

Given an array of functions [f1, f2, f3, ..., fn], return a new function fn that is the function composition of the array of functions.

The function composition of [f(x), g(x), h(x)] is fn(x) = f(g(h(x))).

The function composition of an empty list of functions is the identity function f(x) = x.

You may assume each function in the array accepts one integer as input and returns one integer as output.

 

Example 1:

Input: functions = [x => x + 1, x => x * x, x => 2 * x], x = 4
Output: 65
Explanation:
Evaluating from right to left ...
Starting with x = 4.
2 * (4) = 8
(8) * (8) = 64
(64) + 1 = 65

*/
// Aprroach 1 

var compose = function(functions) {
    
    
    return function(x) {
        let result = x; // create a variable for x ;
        for(let i=functions.length-1;i>=0;i--){ // loop which trev.. from end of functions arrey 
            const fun = functions[i];//fun a variable which store a functions that is at functions[i]
            result = fun(result); // call a functions and store in result;
        }
        return result;
    }
};



// approach  2;
var compose = function(functions) {
    
    return function(x) {
        return functions.reduceRight((acc,cfun)=> cfun(acc),x);//reduceRight(); is a functions which traverce on a arrey from right of the arrey and take two variabl a first is prev (which return by this functions preev time) value and second is current value 
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */