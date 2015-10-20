//=======================================================================
// Copyright 1997, 1998, 1999, 2000 University of Notre Dame.
// Authors: Andrew Lumsdaine, Lie-Quan Lee, Jeremy G. Siek
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================
#include <boost/config.hpp>
#include <iostream>
#include <vector>
#include <utility>
#include <stdio.h>
#include <boost/graph/adjacency_list.hpp>
#include <boost/foreach.hpp>
/*
  Sample Output

  0 <--
  1 <-- 0
  2 <-- 1
  3 <-- 1
  4 <-- 2  3

 */

int main(int , char* [])
{
  using namespace boost;
  using namespace std;
  using namespace boost;
  int z;
  typedef adjacency_list<listS,vecS,bidirectionalS> Graph;
  const int num_vertices1 = 6;
  Graph g(num_vertices1);

  add_edge(0, 1, g);
  add_edge(1, 3, g);
  add_edge(1, 2, g);
  add_edge(2, 4, g);
  add_edge(2, 5, g);
  add_edge(3, 5, g);
  add_edge(3, 4, g);
  add_edge(4, 0, g);
  add_edge(5, 1, g);

  boost::graph_traits<Graph>::vertex_iterator i, end;
  boost::graph_traits<Graph>::in_edge_iterator ei, edge_end;
  boost::graph_traits<Graph>::out_edge_iterator oi, edge_out;
  boost::graph_traits<Graph>::vertex_descriptor vd;
  boost::graph_traits<Graph>::edge_descriptor ed;


  //edges = arestas
  cout << "num Vertices " << num_vertices(g) << "\n";
  cout << "num edges " << num_edges(g) << "\n";
  cout << "out degree " << out_degree(1,g) << "\n";
  cout << "in degree " << in_degree(1,g) << "\n";

  printf("OUT_EDGE\n");
    int x;
    x=num_vertices(g);

    for(boost::tie(i,end) = vertices(g); i != end; ++i)
    {
     cout << *i << " --> ";
     for (boost::tie(oi,edge_out) = out_edges(*i, g); oi != edge_out; ++oi)
     {
         cout << target(*oi, g) << "  ";
     }
     cout << endl;
    }

   printf("\nIN_EDGE\n");
  for(boost::tie(i,end) = vertices(g); i != end; ++i)
  {
    cout << *i << " <-- ";
    for (boost::tie(ei,edge_end) = in_edges(*i, g); ei != edge_end; ++ei)
    {
      cout << source(*ei, g) << "  ";
    }
    cout << endl;
  }

int soma;
int soma1;

  for(z=0;z<x;z++)
  {
      soma=0;soma1=0;
      cout << "z= " << z;
      cout << endl;
      cout << "N out= " << out_degree(z,g);
      cout << endl;
      cout << "N in=  " << in_degree(z,g);
      cout << endl;
      cout << "Vout";
      cout << endl;
      BOOST_FOREACH(ed, boost::out_edges(z,g))
      {
            cout << "edout  " << ed;
            cout << endl;
            cout << "Sai " << target(ed,g);
            cout << endl;
            soma+=target(ed,g);
            cout << "SOMA " << soma;
            cout << endl;
      }
      cout << "Vin";
      cout << endl;
      BOOST_FOREACH(ed, boost::in_edges(z,g))
      {
            cout << "edin  " << ed;
            cout << endl;
            cout << "Entra " << source(ed,g);
            cout << endl;
            soma1+=source(ed,g);
            cout << "SOMA1 " << soma1;
            cout << endl;
      }
  }

  return 0;
}

/*
for i=lastLine-1:-1:300
        %Numero de experiencias de ei para outra
       for j=1:nf
            if (i==lastLine)
                 aux1(i,1) = experience(loop,1) - experience(i,1) - ( dR(i,1) );
                 aux1(i,2) = experience(loop,2) - experience(i,2) - ( dR(i,2) );
            else
               aux1(i,1) = experience(i+1,1) - experience(i,1) -  ( dR(i,1) );
               aux1(i,2) = experience(i+1,2) - experience(i,2) -  ( dR(i,2) );
            end
       end
       %Numero de experiencias que chegam em ei
       for k=1:nt
           if (i==1)
               aux2(i,1) = experience(lastLine,1) - experience(i,1) - ( dR(lastLine,1) );
               aux2(i,2) = experience(lastLine,2) - experience(i,2) - ( dR(lastLine,2) );
           else
               aux2(i,1) = experience(i-1,1) - experience(i,1) - ( dR(i-1,1) );
               aux2(i,2) = experience(i-1,2) - experience(i,2) - ( dR(i-1,2) );
           end

       end
         experience(i,1) = experience(i,1)+rate*(aux1(i,1)+aux2(i,1));
         experience(i,2) = experience(i,2)+rate*(aux1(i,2)+aux2(i,2)) ;
   end

*/
