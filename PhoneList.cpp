#include <cstdio>
#include <cstring>
using namespace std;
struct Trie {
	Trie* p[10];
	bool end, go;
	Trie() {
		memset(p, 0, sizeof(p));
		end = go = false;
	}
	~Trie() {
		for (int i = 0; i < 10; i++)
			if (p[i]) delete(p[i]);
	}
	bool insert(char* key){
		if (*key == '\0') {
			end = true;
			return go;
		}
		int temp = *key - '0';
		if (!p[temp]) {
			p[temp] = new Trie();
		}
		go = true;
		return (end || p[temp]->insert(key + 1));
	}
};
int main()
{
	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		int n;
		scanf("%d", &n);
		Trie* root = new Trie;
		char input[11];
		bool result = true;
		for (int i = 0; i < n; i++) {
			scanf("%s", &input);
			if (result && (root->insert(input))) { // false 삽입만 true 못 간다
				result = false;
			}
		}
		puts(result ? "YES" : "NO");
		delete(root);
	}
}