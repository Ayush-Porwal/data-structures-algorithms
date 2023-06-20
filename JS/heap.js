class Heap {
    constructor() {
        this.heap = [];
    }

    static swap(a, b) {
        const temp = a;
        a = b;
        b = temp;
    }

    get print() {
        console.log(this.heap);
    }

    get top() {
        return this.heap[1];
    }
}

class MinHeap extends Heap {
    constructor() {
        super();
        this.heap = [Number.NEGATIVE_INFINITY, -1, 3, 2, 5, 6, 4];
    }

    get size() {
        return this.heap.length - 1;
    }

    insert(value) {
        this.heap.push(value);
        let heapSize = this.size;
        /// bottom to up
        while (heapSize > 0) {
            console.log("In While...");
            if (this.heap[~~(heapSize / 2)] > this.heap[heapSize]) {
                [this.heap[~~(heapSize / 2)], this.heap[heapSize]] = [
                    this.heap[heapSize],
                    this.heap[~~(heapSize / 2)],
                ];
            }
            heapSize = ~~(heapSize / 2);
        }
    }

    delete() {
        [this.heap[this.size], this.heap[1]] = [
            this.heap[1],
            this.heap[this.size],
        ];
        this.heap.pop();

        let i = 1;
        /// top to bottom
        while (i < this.size) {
            if (2 * i <= this.size && this.heap[2 * i] < this.heap[i]) {
                [this.heap[i], this.heap[2 * i]] = [
                    this.heap[2 * i],
                    this.heap[i],
                ];
            }
            if (2 * i + 1 <= this.size && this.heap[2 * i + 1] < this.heap[i]) {
                [this.heap[i], this.heap[2 * i + 1]] = [
                    this.heap[2 * i + 1],
                    this.heap[i],
                ];
            }
            i++;
        }
    }
}

const minheap = new MinHeap();

minheap.delete();

minheap.print;
