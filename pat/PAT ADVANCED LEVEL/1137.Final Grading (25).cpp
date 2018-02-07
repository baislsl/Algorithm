#include <bits/stdc++.h>

using namespace std;

struct score {
	int mid, final, ass;
	bool mf, ff, af;
	int g;

	score() : mid(0), final(0), ass(0) {
		mf = ff = af = false;
	}
};

int main() {
	int p, m, n;
	cin >> p >> m >> n;
	std::map<string, score> map;
	string name;
	int ss;
	while (p--) {
		cin >> name >> ss;
		map[name].ass = ss;
		map[name].af = true;
	}
	while (m--) {
		cin >> name >> ss;
		map[name].mid = ss;
		map[name].mf = true;
	}
	while (n--) {
		cin >> name >> ss;
		map[name].final = ss;
		map[name].ff = true;
	}

	vector<pair<string, score>> data;
	for (auto i = map.begin(); i != map.end(); i++) {
		score &ss = (*i).second;
		if (!ss.af || ss.ass < 200) continue;
		if (ss.mf && ss.ff && ss.mid > ss.final) {
			ss.g = std::round(ss.mid * 0.4 + ss.final * 0.6);
		} else {
			ss.g = ss.final;
		}
		if (ss.g < 60) continue;

		data.push_back(*i);
	}

	sort(data.begin(), data.end(), [](const pair<string, score> &p1, const pair<string, score> &p2) -> bool {
		return p1.second.g != p2.second.g ? p1.second.g > p2.second.g
				:(p1.first.compare(p2.first) < 0);
	});


	for (auto i : data) {
		score& s = i.second;
		cout << i.first << " "  << s.ass << " "
			 << (s.mf ? s.mid : -1) << " " << (s.ff ? s.final :  -1 ) << " "  << s.g << endl;
	}

}
