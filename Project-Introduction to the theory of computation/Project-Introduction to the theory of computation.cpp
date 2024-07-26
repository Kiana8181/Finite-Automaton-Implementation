#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

#define MARKED 1
#define UNMARKED -1
int total_state, total_symbol, final_state, fin, a;
int transition[100][100], m[100][100], newstate[100][100], arr[100], new_transition[100][100];

class DFA {
public:
	void printDFA(vector<vector<int> > states, vector<vector<vector<int> > > dfa) {
		cout << "  STATE/INPUT  ";
		char a = 'a';
		for (int i = 0; i < dfa[0].size(); i++) {
			cout << "|   " << a++ << "   ";
		}
		cout << endl;
		for (int i = 0; i < states.size(); i++) {
			cout << "{ ";
			for (int h = 0; h < states[i].size(); h++)
				cout << states[i][h] << " ";
			if (states[i].empty()) {
				cout << "^ ";
			}
			cout << "}    ";
			for (int j = 0; j < dfa[i].size(); j++) {
				cout << " | ";
				for (int k = 0; k < dfa[i][j].size(); k++) {
					cout << dfa[i][j][k] << " ";

				}
				if (dfa[i][j].empty()) {
					cout << "^ ";
				}
			}
			cout << endl;
		}
	}
	bool isAcceptByDFA(vector<vector<vector<int> > > dfa, string s, vector<int> FState, vector<vector<int> > state, int alpha) {
		int k = 0;
		for (int i = 0; i < s.size(); i++) {
			int j;
			char a = 'a';
			for (j = 0; j < alpha; j++) {
				if (s[i] != a) a++;
				else break;
			}
			vector<int> nstate;
			for (int g = 0; g < dfa[k][j].size(); g++) {
				nstate.push_back(dfa[k][j][g]);
			}
			if (nstate.size() == 0) return false;
			for (int y = 0; y < state.size(); y++) {
				if (state[y].size() == nstate.size()) {
					for (int t = 0; t < nstate.size(); t++) {
						if (state[y][t] != nstate[t]) break;
						else if (state[y][t] == nstate[t] && t == nstate.size() - 1) k = y;
					}
				}
			}
			if (i == s.size() - 1) {
				for (int e = 0; e < state[k].size(); e++) {
					for (int r = 0; r < FState.size(); r++) {
						if (state[k][e] == FState[r]) return true;
					}
				}
			}
		}
		return false;
	}
	int check(int x)
	{
		int c;
		for (c = 0; c < total_state; c++)
		{
			if (x == arr[c])
			{
				return(0);
			}
		}
		return(1);
	}
	int find_s(int x)
	{
		int i, j;
		for (i = 0; i <= a; i++)
		{
			for (j = 0; j < total_state; j++)
			{
				if (x == newstate[i][j])
					return i;
			}
		}
	}
	void MakeSimpleDFA() {
		int i, j;
		cout << "Enter total number of states neglecting unreachable states:";
		cin >> total_state;
		cout << "Enter total number of allowed symbols :";
		cin >> total_symbol;
		cout << "Enter the final state " << endl;
		cin >> final_state;
		cout << "Enter the transitions :- " << endl;
		for (i = 0; i < total_state; i++) {
			for (j = 0; j < total_symbol; j++) {
				cout << endl << i << " ---> " << char(j + 97) << " :";
				cin >> transition[i][j];
			}
		}
		cout << endl << endl << endl;
		cout << endl << "   TRANSITION TABLE OF ENTERED DFA IS AS FOLLOWS ";
		cout << endl << "*****************************************************" << endl;
		for (i = 0; i < total_symbol; i++)
			cout << "\t" << char(i + 97);
		cout << endl;
		for (i = 0; i < (total_symbol + 1); i++)
			cout << "-\t";
		cout << "\n";
		for (i = 0; i < total_state; i++) {
			cout << "\n" << i << "\t";
			for (j = 0; j < total_symbol; j++) {
				cout << transition[i][j] << "\t";
			}
		}
		cout << endl << endl << "Total number is states :" << total_state;
		cout << endl << "Final state is :" << final_state;
		int k, x, y;
		for (i = 0; i < total_state; i++) {
			for (j = 0; j < total_state; j++) {
				if (j > i) {
					m[i][j] = MARKED;
				}
				else {
					if (((i == final_state && j != final_state) || (i != final_state && j == final_state)) && (i != j)) {
						m[i][j] = MARKED;
					}
					else {
						m[i][j] = UNMARKED;
					}
				}
			}
		}
		for (i = 0; i < total_state; i++) {
			for (j = i + 1; j < total_state; j++) {
				if (m[j][i] == UNMARKED) {
					for (k = 0; k < total_symbol; k++) {
						x = transition[i][k];
						y = transition[j][k];
						if (m[x][y] == MARKED || m[y][x] == MARKED) {
							m[j][i] = MARKED;
							break;
						}
					}
				}
			}
		}
		k = 0;
		int b = 0;
		for (i = 0; i < total_state; i++) {
			for (j = 0; j < total_state; j++) {
				newstate[i][j] = total_state;
			}
		}
		for (i = 0; i < total_state; i++) {
			arr[i] = total_state;
			for (i = 0; i < total_state; i++) {
				if (check(i) != 0) {
					b = 0;
					newstate[a][b] = i;
					for (j = i + 1; j < total_state; j++) {
						if (m[j][i] == UNMARKED) {
							arr[k] = j;
							k++;
							newstate[a][b + 1] = j;
						}
					}
					a++;
				}
			}
		}
		int s1;
		for (i = 0; i <= a; i++) {
			x = newstate[i][0];
			for (k = 0; k < total_symbol; k++) {
				s1 = transition[x][k];
				fin = find_s(s1);
				new_transition[i][k] = fin;
			}
		}
		final_state = find_s(final_state);
		cout << "\n\n\n";
		cout << "\n   MINIMIZED DFA TABLE";
		cout << "\n****************************\n\t";
		for (i = 0; i < total_symbol; i++)
			cout << char(i + 97) << "\t";
		cout << "\n";
		for (i = 0; i < (total_symbol + 1); i++)
			cout << "-\t";
		cout << "\n";
		for (i = 0; i < a; i++) {
			cout << "\n" << i << "\t";
			for (j = 0; j < total_symbol; j++) {
				cout << new_transition[i][j] << "\t";
			}
		}
		cout << endl << endl << "Total number of new state is :" << a;
		cout << endl << "Final State is :" << final_state << endl;
	}
};

class NFA {
public:
	void printNFA(vector<vector<vector<int> > > table) {
		cout << "  STATE/INPUT  |";
		char a = 'a';
		for (int i = 0; i < table[0].size() - 1; i++) {
			cout << "   " << a++ << "   |";
		}
		cout << "   ^   " << endl << endl;
		for (int i = 0; i < table.size(); i++) {
			cout << "       " << i << "    ";
			for (int j = 0; j < table[i].size(); j++) {
				cout << "   |   ";
				if (table[i][j].size() == 0) cout << " ";
				for (int k = 0; k < table[i][j].size(); k++) {
					cout << table[i][j][k];
				}
			}
			cout << endl;
		}
	}
	vector<int> closure(int s, vector<vector<vector<int> > > v) {
		vector<int> t;
		queue<int> q;
		t.push_back(s);
		int a = v[s][v[s].size() - 1].size();
		for (int i = 0; i < a; i++) {
			t.push_back(v[s][v[s].size() - 1][i]);
			q.push(t[i]);
		}
		while (!q.empty()) {
			int f = q.front();
			q.pop();
			if (!v[f][v[f].size() - 1].empty()) {
				int u = v[f][v[f].size() - 1].size();
				for (int i = 0; i < u; i++) {
					int y = v[f][v[f].size() - 1][i];
					if (find(t.begin(), t.end(), y) == t.end()) {
						t.push_back(y);
						q.push(y);
					}
				}
			}
		}
		return t;
	}
	void CreateEquivalentDFA(vector<vector<vector<int> > > table, int alpha, vector<vector<vector<int> > > dfa, vector<vector<int> > states) {
		cout << "************************* NFA to DFA *************************" << endl << endl;
		DFA d;
		cout << "***** TRANSITION TABLE OF NFA *****" << endl;
		printNFA(table);
		cout << endl << "***** TRANSITION TABLE OF DFA *****" << endl;
		states.push_back(closure(0, table));
		queue<vector<int> > q;
		q.push(states[0]);
		while (!q.empty()) {
			vector<int> f = q.front();
			q.pop();
			vector<vector<int> > v;
			for (int i = 0; i < alpha; i++) {
				vector<int> t;
				set<int> s;
				for (int j = 0; j < f.size(); j++) {

					for (int k = 0; k < table[f[j]][i].size(); k++) {
						vector<int> cl = closure(table[f[j]][i][k], table);
						for (int h = 0; h < cl.size(); h++) {
							if (s.find(cl[h]) == s.end())
								s.insert(cl[h]);
						}
					}
				}
				for (set<int >::iterator u = s.begin(); u != s.end(); u++)
					t.push_back(*u);
				v.push_back(t);
				if (find(states.begin(), states.end(), t) == states.end())
				{
					states.push_back(t);
					q.push(t);
				}
			}
			dfa.push_back(v);
		}
		d.printDFA(states, dfa);
	}
	bool isAcceptByNFA(vector<vector<vector<int> > > table, int alpha, string s, vector<int> FState) {
		vector<vector<vector<int> > > dfa;
		vector<vector<int> > states;
		states.push_back(closure(0, table));
		queue<vector<int> > q;
		q.push(states[0]);
		while (!q.empty()) {
			vector<int> f = q.front();
			q.pop();
			vector<vector<int> > v;
			for (int i = 0; i < alpha; i++) {
				vector<int> t;
				set<int> s;
				for (int j = 0; j < f.size(); j++) {

					for (int k = 0; k < table[f[j]][i].size(); k++) {
						vector<int> cl = closure(table[f[j]][i][k], table);
						for (int h = 0; h < cl.size(); h++) {
							if (s.find(cl[h]) == s.end())
								s.insert(cl[h]);
						}
					}
				}
				for (set<int >::iterator u = s.begin(); u != s.end(); u++)
					t.push_back(*u);
				v.push_back(t);
				if (find(states.begin(), states.end(), t) == states.end())
				{
					states.push_back(t);
					q.push(t);
				}
			}
			dfa.push_back(v);
		}
		DFA d;
		return d.isAcceptByDFA(dfa, s, FState, states, alpha);
	}
};


int main() {
	int n, alpha, m;
	vector<int> FState;
	vector<vector<int> > states;
	cout << "Enter total number of states in NFA : ";
	cin >> n;
	cout << "Enter number of elements in alphabet : ";
	cin >> alpha;
	cout << "Enter number of final states : ";
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		FState.push_back(x);
	}
	vector<vector<vector<int> > > table; //NFA
	vector<vector<vector<int> > > dfa;  //DFA
	for (int i = 0; i < n; i++) {
		cout << "For state " << i << endl;
		vector< vector< int > > v;
		char a = 'a';
		int y, yn;
		for (int j = 0; j < alpha; j++) {
			vector<int> t;
			cout << "Enter number of output states for input " << a++ << " : ";
			cin >> yn;
			cout << "Enter output states :" << endl;
			for (int k = 0; k < yn; k++) {
				cin >> y;
				t.push_back(y);
			}
			v.push_back(t);
		}
		vector<int> t;
		cout << "Enter number of output states for input ^ : ";
		cin >> yn;
		cout << "Enter output states :" << endl;
		for (int k = 0; k < yn; k++) {
			cin >> y;
			t.push_back(y);
		}
		v.push_back(t);
		table.push_back(v);
	}
	NFA nfa;
	DFA df;
	int w = 0;
	while (w != 7) {
		cout << "***********************************MENU***********************************" << endl;
		cout << "1.Is The String Accept By NFA?" << endl << "2.Is The String Accept By DFA?" << endl << "3.Create Equivalent DFA" << endl << "4.Make Simple DFA" << endl << "5.Print NFA" << endl << "6.Print DFA" << endl << "7.EXIT" << endl;
		cin >> w;
		dfa.clear();
		states.clear();
		if (w == 1) {
			string s;
			cout << "Enter your string: " << endl;
			cin >> s;
			if (nfa.isAcceptByNFA(table, alpha, s, FState))
				cout << "TRUE" << endl;
			else cout << "FALSE" << endl;
		}
		if (w == 2) {
			string s;
			cout << "Enter your string: " << endl;
			cin >> s;
			states.push_back(nfa.closure(0, table));
			queue<vector<int> > q;
			q.push(states[0]);
			while (!q.empty()) {
				vector<int> f = q.front();
				q.pop();
				vector<vector<int> > v;
				for (int i = 0; i < alpha; i++) {
					vector<int> t;
					set<int> s;
					for (int j = 0; j < f.size(); j++) {

						for (int k = 0; k < table[f[j]][i].size(); k++) {
							vector<int> cl = nfa.closure(table[f[j]][i][k], table);
							for (int h = 0; h < cl.size(); h++) {
								if (s.find(cl[h]) == s.end())
									s.insert(cl[h]);
							}
						}
					}
					for (set<int >::iterator u = s.begin(); u != s.end(); u++)
						t.push_back(*u);
					v.push_back(t);
					if (find(states.begin(), states.end(), t) == states.end())
					{
						states.push_back(t);
						q.push(t);
					}
				}
				dfa.push_back(v);
			}
			if (df.isAcceptByDFA(dfa, s, FState, states, alpha))
				cout << "TRUE" << endl;
			else cout << "FALSE" << endl;
		}
		if (w == 3) {
			nfa.CreateEquivalentDFA(table, alpha, dfa, states);
		}
		if (w == 4) {
			df.MakeSimpleDFA();
		}
		if (w == 5) {
			nfa.printNFA(table);
		}
		if (w == 6) {
			states.push_back(nfa.closure(0, table));
			queue<vector<int> > q;
			q.push(states[0]);
			while (!q.empty()) {
				vector<int> f = q.front();
				q.pop();
				vector<vector<int> > v;
				for (int i = 0; i < alpha; i++) {
					vector<int> t;
					set<int> s;
					for (int j = 0; j < f.size(); j++) {

						for (int k = 0; k < table[f[j]][i].size(); k++) {
							vector<int> cl = nfa.closure(table[f[j]][i][k], table);
							for (int h = 0; h < cl.size(); h++) {
								if (s.find(cl[h]) == s.end())
									s.insert(cl[h]);
							}
						}
					}
					for (set<int >::iterator u = s.begin(); u != s.end(); u++)
						t.push_back(*u);
					v.push_back(t);
					if (find(states.begin(), states.end(), t) == states.end())
					{
						states.push_back(t);
						q.push(t);
					}
				}
				dfa.push_back(v);
			}
			df.printDFA(states, dfa);
		}
		if (w == 7) break;
	}
}
