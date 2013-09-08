//teorema de pick.

/* given a simple poligon constructed on a grid of equal-distanced points
(p.e. point with integer coordinates) such that all the polygon's vertices are grid points, Pick's theorem provides a simple formula for calculating the area A of this polygon in terms of the number i of interior points located
in the polygon and the number of boundary points placed on the polygon 
perimeter:*/

int pick(int i, int b){
	return i+(b/2)-1;
}
int main(){
	cout<<pick(39,14)<<endl;
	return 0;
}
