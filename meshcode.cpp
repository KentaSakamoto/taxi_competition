#include <Rcpp.h>
#include <vector>
using namespace Rcpp;
using namespace std;
// Enable C++11 via this plugin (Rcpp 0.10.3 or later)
// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::export]]

DataFrame ride_on_data(int s, int t,DataFrame hos, DataFrame taxi) {
  DataFrame D;
  NumericVector res;
  NumericVector hosmesh = hos[8];
  NumericVector taximesh = taxi[6];
  int cnt; // cnt : カウンタ変数, s : hosデータの列数, t : taxiデータの列数
  for (int i  = 0; i < s; ++i) {
    for (int j = 0; j < t; ++j) {
      if (hosmesh[i] == taximesh[j]) { // メッシュコードが一致したときにカウンタを一つ増やす
        cnt += 1;
      }
      res.push_back(cnt); // 上記のif文が終わったらcntを配列に追加する
      cnt = 0;
    }
  }
  
  D = DataFrame::create(Named("hospital") = hos[2],Named("number") = res);
  return D;
}