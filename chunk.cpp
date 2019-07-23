/* Bismillahirrahmanirrahim */
/* Author : Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>

// MACROS SAMPAH
#define Jehian using
#define Norman namespace
#define Saviero std

Jehian Norman Saviero;

// MACROS TYPE
typedef long l;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<l,l> pl;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<l> vl;
typedef vector<ll> vll;

// MACROS FOR PRINT
#define nl printf("\n")
#define sp printf(" ")

// MACROS FOR ATTRIBUTE
#define fi first
#define se second

// MACROS FOR FUNCTION AND METHOD
#define eb emplace_back
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ALL(x) (x).begin(), (x).end()
#define ALLN(x,n) (x), (x)+(n)
#define CUBE(x) (SQR(x)*(x))
#define SET(x,y) for (int _qwe = sizeof(x)/sizeof(x[0]); _qwe; ) x[--_qwe] = (y)
#define SQR(x) ((x)*(x))
#define SSORT(x,sz) sort(ALLN(x,sz))
#define RESET(x) memset((x), 0, sizeof(x))
#define VSORT(x) sort(ALL(x))

// MACROS READ INPUT
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%ld", &x)
#define scll(x) scanf("%lld", &x)
#define scul(x) scl(x)
#define scull(x) scll(x)

int main(int argc, char** argv) {
	if (argc < 2) {
		fprintf(stderr, "Paramater kurang dari 2\n");
		fprintf(stderr, "Argument format: ./<namefile>.out <input file>.nt <chunk size>\n");
		exit(0);
	}
	int length = strlen(argv[1]);
	int pos = length-1;
	for (int i = length-1; i >= 0; --i) {
		if (argv[1][i] == '.') {
			pos = i;
			break;
		}
	}
	string dirName;
	for (int i = 0; i < pos; ++i) {
		dirName.pb(argv[1][i]);
	}
	string arg = "mkdir " + dirName;
	system(arg.c_str());
	int sz = 1000000;
	if (argc >= 3) {
		sz = max(10000, min(sz, atoi(argv[2])));
	}
	string s;
	ifstream in;
	in.open(argv[1]);
	ofstream ofs;
	int curr = 0;
	string filename = "rdf";
	ostringstream oss;
	oss << filename << '-' << ++curr << ".nt";
	int cnt = 0;
	ofs.open(oss.str().c_str());
	int tot = 0;
	while (getline(in,s)) {
		cerr << "Progress: " << tot++ << '\n';
		ofs << s << '\n';
		++cnt;
		if (cnt == sz) {
			ofs.close();
			oss.str("");
			oss << dirName << "/" << filename << '-' << ++curr << ".nt";
			ofs.open(oss.str().c_str());
			cnt = 0;
		}
	}
	ofs.close();
	oss.str("");
	return 0;
}