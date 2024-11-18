#include <iostream>

#include <cmath>
#include <iostream>
#include <stack>
#include <stdlib.h>

using namespace std;

struct ponto {
    int x, y;
};
double distancia(ponto p1, ponto p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y));
}

struct segmento {
    ponto a, b;
};ponto p0;
 
// A utility function to find next to top in a stack
ponto nextToTop(stack<ponto> &S)
{
    ponto p = S.top();
    S.pop();
    ponto res = S.top();
    S.push(p);
    return res;
}
 
// A utility function to swap two points
void swap(ponto &p1, ponto &p2)
{
    ponto temp = p1;
    p1 = p2;
    p2 = temp;
}
 
// A utility function to return square of distance
// between p1 and p2
int distSq(ponto p1, ponto p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}
int orientation(ponto p, ponto q, ponto r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // collinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compare(const void *vp1, const void *vp2)
{
   ponto *p1 = (ponto *)vp1;
   ponto *p2 = (ponto *)vp2;
 
   // Find orientation
   int o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;
 
   return (o == 2)? -1: 1;
}


float area_triangulo(ponto a, ponto b, ponto c){
    return (
        a.x * b.y - a.y * b.x + 
        a.y * c.x - a.x * c.y +
        b.x * c.y - b.y * c.x 
    )/2.0;
}
void grahan_scan(ponto points[], int n, ponto pontoTestado)
{
   // Find the bottommost point
   int ymin = points[0].y, min = 0;
   for (int i = 1; i < n; i++)
   {
     int y = points[i].y;
 
     // Pick the bottom-most or choose the left
     // most point in case of tie
     if ((y < ymin) || (ymin == y &&
         points[i].x < points[min].x))
        ymin = points[i].y, min = i;
   }
 
   // Place the bottom-most point at first position
   swap(points[0], points[min]);
 
   // Sort n-1 points with respect to the first point.
   // A point p1 comes before p2 in sorted output if p2
   // has larger polar angle (in counterclockwise
   // direction) than p1
   p0 = points[0];
   qsort(&points[1], n-1, sizeof(ponto), compare);
 
   // If two or more points make same angle with p0,
   // Remove all but the one that is farthest from p0
   // Remember that, in above sorting, our criteria was
   // to keep the farthest point at the end when more than
   // one points have same angle.
   int m = 1; // Initialize size of modified array
   for (int i=1; i<n; i++)
   {
       // Keep removing i while angle of i and i+1 is same
       // with respect to p0
       while (i < n-1 && orientation(p0, points[i],
                                    points[i+1]) == 0)
          i++;
 
 
       points[m] = points[i];
       m++;  // Update size of modified array
   }
 
   // If modified array of points has less than 3 points,
   // convex hull is not possible
   if (m < 3) return;
 
   // Create an empty stack and push first three points
   // to it.
   stack<ponto> S;
   S.push(points[0]);
   S.push(points[1]);
   S.push(points[2]);
 
   // Process remaining n-3 points
   for (int i = 3; i < m; i++)
   {
      // Keep removing top while the angle formed by
      // points next-to-top, top, and points[i] makes
      // a non-left turn
      while (S.size()>1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
   }
 
    float distance = 0;
   // Now stack has the output points, print contents of stack
   bool isFirst = true;
   bool isLast = false;
   ponto firstponto;
   ponto previous;
   bool dentro = true;
   while (!S.empty())
   {
       ponto p = S.top();
       if(pontoTestado.x == p.x && pontoTestado.y == p.y){
            dentro = false;
       }
       S.pop();
       // Se for ultimo, calcular como extra a distancia do ultimo com o primeiro
       if(S.empty()){
        distance += distancia(p, firstponto);
       }
        if(isFirst){
            firstponto = p;
            isFirst = false;
            previous = p;
        } else {
            distance += distancia(previous, p);
            previous = p;
        }
        
       
       
   }
   if(dentro){
    cout << "DENTRO";
   } else {
    cout << "!(DENTRO)";
   }
}
// Sentido horario negativo
// Sentido anti horario positivo
int lado(segmento ab, ponto c){
    float area = area_triangulo(ab.a, ab.b, c);
    if(area < 0)
        return -1;
    if(area > 0)
        return 1;
    return 0;
}

int main(){
    int numVertices;
    cin >> numVertices;
    ponto pontos[numVertices + 1];
    for(int i = 0; i< numVertices; i++){
        cin >> pontos[i].x >> pontos[i].y;
    }
    ponto pontoTestado;

    cin >> pontoTestado.x >> pontoTestado.y;
    pontos[numVertices] = {pontoTestado.x, pontoTestado.y};
    grahan_scan(pontos, numVertices,pontoTestado);
    return 0;
}