/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    var num1 = 0
    var num2 = 0
    await promise1.then( function(val) {
        num1 = val
    })
    await promise2.then( function(val) {
        num2 = val
    })
         
    return num1 + num2
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */