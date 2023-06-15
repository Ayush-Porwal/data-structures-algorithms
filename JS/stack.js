export class Stack {
    constructor() {
        this.stack = [];
    }

    isEmpty() {
        return this.stack.length === 0;
    }

    top() {
        return this.stack[this.stack.length - 1];
    }

    size() {
        return this.stack.length;
    }

    push(value) {
        this.stack.push(value);
    }

    pop(value) {
        this.stack.pop(value);
    }
}
