struct point{
    int x, y;
};

point points[10];


// Saber si dado 4 puntos , forman un rectangulo o cuadrado
int IsOrthogonal(point a, point b, point c){
	return (b.x - a.x) * (b.x - c.x) + (b.y - a.y) * (b.y - c.y) == 0;
}

// Para rectangulo
int IsRectangle(point a, point b, point c, point d){
	return IsOrthogonal(a, b, c) &&
         IsOrthogonal(b, c, d) &&
         IsOrthogonal(c, d, a);
}
bool IsRectangleAnyOrder(point a, point b, point c, point d){
  return IsRectangle(a, b, c, d) ||
         IsRectangle(b, c, a, d) ||
         IsRectangle(c, a, b, d);
}

//Para cuadrado( usa para rectangulo )
bool isSquare(point a, point b, point c, point d){
	int64 d1 = (a.x - b.x) * (a.x - b.x) +  (a.y - b.y) * (a.y - b.y);
  int64 d2 = (b.x - c.x) * (b.x - c.x) +  (b.y - c.y) * (b.y - c.y);
  int64 d3 = (c.x - d.x) * (c.x - d.x) +  (c.y - d.y) * (c.y - d.y);
  int64 d4 = (a.x - d.x) * (a.x - d.x) +  (a.y - d.y) * (a.y - d.y);
  if(d1 == d2 && d2 == d3 && d3 == d4 && d4 == d1) return 1;
  return 0;
}

bool isSAny(point a, point b, point c, point d){
	if(!IsRectangleAnyOrder(a,  b,  c, d)) return 0;
  return isSquare(a, b, c, d) ||
         isSquare(b, c, a, d) ||
         isSquare(c, a, b, d);
}
