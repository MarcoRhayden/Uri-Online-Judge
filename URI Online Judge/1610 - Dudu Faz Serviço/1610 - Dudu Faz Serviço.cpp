#include <bits/stdc++.h>
using namespace std;

class Grafo
{
	int vertices;
	list<int> *adj;

public:
	Grafo(int v);
	void adicionarAresta(int v1, int v2);
	bool dfs(int v);
	bool contemCiclo();
};

Grafo::Grafo(int v)
{
	vertices = v;
	adj = new list<int>[v];
}

void Grafo::adicionarAresta(int v1, int v2)
{
	adj[v1].push_back(v2);
}

bool Grafo::dfs(int v)
{
	stack<int> pilha;
	bool visitados[vertices], pilha_rec[vertices];

	for (int x = 0; x < vertices; x++)
	{
		visitados[x] = false;
		pilha_rec[x] = false;
	}

	while (true)
	{
		if (!visitados[v])
		{
			pilha.push(v);
			visitados[v] = true;
			pilha_rec[v] = true;
		}

		list<int>::iterator it;
		bool achou = false;

		for (it = adj[v].begin(); it != adj[v].end(); it++)
		{
			if (pilha_rec[*it])
			{
				return true;
			}
			else if (!visitados[*it])
			{
				achou = true;
				break;
			}
		}

		if (achou)
		{
			v = *it;
		}
		else
		{
			pilha_rec[pilha.top()] = false;
			pilha.pop();

			if (pilha.empty())
			{
				break;
			}

			v = pilha.top();
		}
	}

	return(false);
}

bool Grafo::contemCiclo()
{
	bool response = false;

	for (int i = 0; i < vertices; i++)
	{
		if (dfs(i))
		{
			response = true;
			i = vertices;
		}
	}

	return(response);
}

int main(int argc, char *argv[])
{
	int T;
	cin >> T;

	int N, M;

	while (T > 0)
	{
		cin >> N; // VERTICES
		cin >> M;  // ARESTAS

		Grafo grafo(N);

		for (int x = 0; x < M; x++)
		{
			int v1, v2;

			cin >> v1;
			cin >> v2;

			grafo.adicionarAresta(v1-1, v2-1);
		}

		if (grafo.contemCiclo())
		{
			cout << "SIM" << endl;
		}
		else
		{
			cout << "NAO" << endl;
		}

		T--;
	}

    return(0);
}
