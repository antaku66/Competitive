#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = s; i < (n); ++i)

namespace {

struct Edge {
  Edge(int a, int b, int c) : to_(a), cap_(b), rev_(c) {}
  int to_, cap_, rev_;
};

class FordFulkerson {
 public:
  // ���_�� n�i 0 ~ n-1 �܂Łj�̎c�]�O���t������
  FordFulkerson(int n) : size_(n) {
    graph_.resize(n);
    used_ = vector<bool>(n, false);
  }

  // ���_ a ���� b �Ɍ������A��� c ���b�g���^�b�̕ӂ�ǉ�
  void AddEdge(int a, int b, int c) {
    int current_a = graph_[a].size();  // �����_�ł� graph_[a] �̗v�f��
    int current_b = graph_[b].size();  // �����_�ł� graph_[b] �̗v�f��
    graph_[a].push_back(Edge{b, c, current_b});
    graph_[b].push_back(Edge{a, 0, current_a});
  }

  // ���_ s ���璸�_ t �܂ł̍ő�t���[�̑����ʂ�Ԃ�
  int Calc(int s, int t) {
    int totalFlow = 0;
    while (true) {
      for (int i = 0; i < size_; ++i) used_[i] = false;
      int f = DFS(s, t, 1e9);

      // �t���[�𗬂��Ȃ��Ȃ����瑀��I��
      if (f == 0) break;
      totalFlow += f;
    }
    return totalFlow;
  }

 private:
  // �[���D��T���iF �̓X�^�[�g���� pos �ɓ��B����ߒ��ł�
  // " �c�]�O���t�̕ӂ̗e�� " �̍ŏ��l�j
  // �Ԃ�l�͗������t���[�̗ʁi�����Ȃ��ꍇ 0 ��Ԃ��j
  int DFS(int pos, int goal, int F) {
    // �S�[���ɓ����F�t���[�𗬂���I
    if (pos == goal) return F;
    used_[pos] = true;

    for (int i = 0; i < graph_[pos].size(); i++) {
      // �e�� 0 �̕ӂ͎g���Ȃ�
      if (graph_[pos][i].cap_ == 0) continue;

      // ���ɖK�₵�����_�ɍs���Ă��Ӗ����Ȃ�
      if (used_[graph_[pos][i].to_]) continue;

      // �ړI�n�܂ł̃p�X��T��
      int flow = DFS(graph_[pos][i].to_, goal, min(F, graph_[pos][i].cap_));

      // �t���[�𗬂���ꍇ�A�c�]�O���t�̗e�ʂ� flow ��������������
      if (flow >= 1) {
        graph_[pos][i].cap_ -= flow;
        graph_[graph_[pos][i].to_][graph_[pos][i].rev_].cap_ += flow;
        return flow;
      }
    }

    // ���ׂĂ̕ӂ�T�����Ă�������Ȃ�����
    return 0;
  }

  size_t size_;
  vector<vector<Edge>> graph_;
  vector<bool> used_;
};

}  // namespace