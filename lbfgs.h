//
//  CRF++ -- Yet Another CRF toolkit
//
//  $Id: lbfgs.h 1588 2007-02-12 09:03:39Z taku $;
//
//  Copyright(C) 2005-2007 Taku Kudo <taku@chasen.org>
//
#ifndef MECAB_LBFGS_H
#define MECAB_LBFGS_H

#include <vector>
#include "common.h"

extern "C" {
  extern void lbfgs(int* n, int* m, double* x, double* f, double* g,
                    int* diagco, double* diag, int* iprint, double* eps,
                    double* xtol, double* w, int* iflag);
}

namespace CRFPP {

  class LBFGS {
  private:
    int n_;
    int m_;
    int iflag_;
    whatlog what_;
    std::vector <double> diag_;
    std::vector <double> w_;

  public:
    explicit LBFGS(): n_(0), m_(5), iflag_(0) {}
    virtual ~LBFGS() {}

    const char *what() { return what_.str(); }

    int init(int _n, int _m) {
      n_ = _n;
      m_ = _m;
      w_.resize(n_ *(2 * m_ + 1) + 2 * m_);
      diag_.resize(n_);
      return 0;
    }

    int optimize(double *x, double *f, double *g) {
      int iprint[] = {-1, 0};
      double eta  = 1e-7;
      double xtol = 1e-7;
      int diagco = 0;
      lbfgs(&n_, &m_, x, f, g, &diagco, &diag_[0],
            iprint, &eta, &xtol, &w_[0], &iflag_);

      if (iflag_ < 0) {
        CHECK_FALSE(false) << "routine stops with unexpected error";
        return -1;
      }

      if (iflag_ == 0) return 0;   // terminate

      return 1;   // evaluate next f and g
    }
  };
}

#endif
