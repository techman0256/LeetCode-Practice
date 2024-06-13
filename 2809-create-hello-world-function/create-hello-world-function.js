/**
 * @return {Function}
 */
var createHelloWorld = function() {
    const f = function() {
        return "Hello World"
    }
    return f;
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */