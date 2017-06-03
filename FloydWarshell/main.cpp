#include <iostream>


const int INF = INT_MAX;
const size_t V = 4;

void printGraph(int graph[][V])
{
	for (size_t i = 0; i < V; ++i)
	{
		for (size_t j = 0; j < V; ++j)
			if (graph[i][j] == INF)
				std::cout << "INF ";
			else
				std::cout << graph[i][j] << " ";

		std::cout << std::endl;
	}
}

void floyd(int graph[][V])
{
	int distances[V][V];
	for (size_t i = 0; i < V; ++i)
		for (size_t j = 0; j < V; ++j)
			distances[i][j] = graph[i][j];

	for (size_t k = 0; k < V; ++k)
		for (size_t i = 0; i < V; ++i)
			for (size_t j = 0; j < V; ++j)
				if (distances[i][k] != INF && distances[k][j] != INF)
					if (distances[i][k] + distances[k][j] < distances[i][j])
						distances[i][j] = distances[i][k] + distances[k][j];

	printGraph(distances);
}

int main()
{
	int graph[V][V] = { { 0, 5, INF, 10 },
						{ INF, 0, 3, INF },
						{ INF, INF, 0, 1 },
						{ INF, INF, INF, 0 } };

	floyd(graph);
}