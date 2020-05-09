#include <stdio.h>

int Vertex_Count, Edge;
int map[1001][1001];
int visit_DFS[1001];
int visit_BFS[1001];
int queue[1001];
int rear, front;

void DFS(int Vertex)
{
	visit_DFS[Vertex] = 1;
	printf("%d ", Vertex);

	for (int i = 1; i <= Vertex_Count; i++)
	{
		if (map[Vertex][i] == 1 && !visit_DFS[i])
		{
			visit_DFS[i] = 1;
			DFS(i);
		}
	}
}

void BFS(int Vertex)
{
	visit_BFS[Vertex] = 1;
	queue[rear++] = Vertex;

	while (front < rear)
	{
		Vertex = queue[front++];
		printf("%d ", Vertex);

		for (int i = 1; i <= Vertex_Count; i++)
		{
			if (map[Vertex][i] == 1 && !visit_BFS[i])
			{
				visit_BFS[i] = 1;
				queue[rear++] = i;
			}
		}
	}
}

int main()
{
	int Vertex_1, Vertex_2;
	int start;

	scanf("%d %d %d", &Vertex_Count, &Edge, &start);

	for (int i = 1; i <= Edge; i++)
	{
		scanf("%d %d", &Vertex_1, &Vertex_2);
		map[Vertex_1][Vertex_2] = map[Vertex_2][Vertex_1] = 1;
	}

	DFS(start);
	printf("\n");
	BFS(start);

	return 0;
}