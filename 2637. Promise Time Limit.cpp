/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}

 Given an asynchronous function fn and a time t in milliseconds, return a new time limited version of the input function. fn takes arguments provided to the time limited function.

The time limited function should follow these rules:

    If the fn completes within the time limit of t milliseconds, the time limited function should resolve with the result.
    If the execution of the fn exceeds the time limit, the time limited function should reject with the string "Time Limit Exceeded".

 

Example 1:

Input: 
fn = async (n) => { 
  await new Promise(res => setTimeout(res, 100)); 
  return n * n; 
}
inputs = [5]
t = 50
Output: {"rejected":"Time Limit Exceeded","time":50}



here what we should here 

we have a given time let t1 and given a functions which take some time let t2 
if t2 is more then t1 then return a a message "Time limited exceeded" other wise return the
output given by this functions 

 */
var timeLimit = function (fn, t) {

    return async function (...args) {
        return new Promise((resolve, reject) => {
            setTimeout(() => { reject("Time Limit Exceeded") }, t);

            fn(...args).then(resolve).catch(reject);

        })

    }
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */