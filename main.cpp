#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

class solution {
public:
	solution() = default;

	virtual ~solution() = default;

private:
	int n_{};
	int s_{};
	vi v_{};
	int ans_{};

public:
	void input() {
		cin >> n_ >> s_;

		v_ = vi(n_);
		for (auto i = 0; i < n_; ++i) {
			cin >> v_[i];
		}
	}

	void solve() {
		ans_ = 0;
		solvePart(0, 0, 0);
	}

	void printAns() {
		cout << ans_;
	}

private:
	void solvePart(int sum, int ct, int used) {
		if (n_ == ct) {
			if (0 < used &&
				s_ == sum) {
				++ans_;
			}

			return;
		}

		solvePart(sum, ct + 1, used);
		solvePart(sum + v_[ct], ct + 1, used + 1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	auto s = solution{};
	s.input();
	s.solve();
	s.printAns();

	return 0;
}