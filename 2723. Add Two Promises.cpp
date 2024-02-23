/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}

 Given two promises promise1 and promise2, return a new promise. promise1 and promise2 will both resolve with a number. The returned promise should resolve with the sum of the two numbers.

 

Example 1:

Input: 
promise1 = new Promise(resolve => setTimeout(() => resolve(2), 20)), 
promise2 = new Promise(resolve => setTimeout(() => resolve(5), 60))
Output: 7
Explanation: The two input promises resolve with the values of 2 and 5 respectively. The returned promise should resolve with a value of 2 + 5 = 7. The time the returned promise resolves is not judged for this problem.

 */
var addTwoPromises = async function(promise1, promise2) {

    return new Promise((res,rej)=>{ // create a new promise and inside it two paramiter resolve and reject 
        promise1.then((val1)=>{   // after resolve the promise1 take value in val1 
            promise2.then((val2)=>{   // after resolve the promise2 take value in val2
                return res(val1+val2); // return res1+ress2 as a resolve of our promise
            })
        })
    })
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */