class Point {
    constructor(x, y) {
        this.x = x;
        this.y = y;
    }

    static distanceFromOrigin(p) {
        return Math.hypot(p.x, p.y);
    }
}

const P1 = new Point(3, 4);

console.log(Point.distanceFromOrigin(P1));
