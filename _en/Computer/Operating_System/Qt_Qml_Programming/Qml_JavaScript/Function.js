.pragma library

function factorial(a) {
    a = parseInt(a)
    if(a <= 0) {
        return 1;
    } else {
        return a * factorial(a - 1)
    }
}

function jsFunction() {
    console.log("called JavaScript function")
}
