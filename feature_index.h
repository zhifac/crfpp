//
//  CRF++ -- Yet Another CRF toolkit
//
//  $Id: feature_index.h 1588 2007-02-12 09:03:39Z taku $;
//
//  Copyright(C) 2005-2007 Taku Kudo <taku@chasen.org>
//
#ifndef CRFPP_FEATURE_INDEX_H_
#define CRFPP_FEATURE_INDEX_H_

#include <vector>
#include <map>
#include <iostream>
#include "common.h"
#include "scoped_ptr.h"
#include "feature_cache.h"
#include "path.h"
#include "node.h"
#include "freelist.h"
#include "mmap.h"
#include "darts.h"

namespace CRFPP {
class TaggerImpl;

class Allocator {
 public:
  explicit Allocator(size_t thread_num)
      : thread_num_(thread_num),
        feature_cache_(new FeatureCache),
        char_freelist_(8192) {
    init();
  }

  Allocator() : thread_num_(1),
                feature_cache_(new FeatureCache),
                char_freelist_(8192) {
    init();
  }

  virtual ~Allocator() {}

  char *strdup(const char *str);

  Path *newPath(size_t thread_id) {
    return path_freelist_[thread_id].alloc();
  }

  Node *newNode(size_t thread_id) {
    return node_freelist_[thread_id].alloc();
  }

  void clear() {
    feature_cache_->clear();
    char_freelist_.free();
    for (size_t i = 0; i < thread_num_; ++i) {
      path_freelist_[i].free();
      node_freelist_[i].free();
    }
  }

  FeatureCache *feature_cache() const {
    return feature_cache_.get();
  }

  size_t thread_num() const {
    return thread_num_;
  }

 private:
  void init(){
    path_freelist_.reset(new FreeList<Path> [thread_num_]);
    node_freelist_.reset(new FreeList<Node> [thread_num_]);
    for (size_t i = 0; i < thread_num_; ++i) {
      path_freelist_[i].set_size(8192 * 16);
      node_freelist_[i].set_size(8192);
    }
  }

  size_t         thread_num_;
  scoped_ptr<FeatureCache> feature_cache_;
  FreeList<char>           char_freelist_;
  scoped_array< FreeList<Path> > path_freelist_;
  scoped_array< FreeList<Node> > node_freelist_;
};

class FeatureIndex {
 public:
  static const unsigned int version = MODEL_VERSION;

  size_t size() const  { return maxid_; }
  size_t xsize() const { return xsize_; }
  size_t ysize() const { return y_.size(); }
  const char* y(size_t i) const { return y_[i].c_str(); }
  void   set_alpha(const double *alpha) { alpha_ = alpha; }
  const float *alpha_float() { return alpha_float_; }
  const double *alpha() const { return alpha_; }
  void set_cost_factor(double cost_factor) { cost_factor_ = cost_factor; }
  double cost_factor() const { return cost_factor_; }

  void calcCost(Node *node) const;
  void calcCost(Path *path) const;

  bool buildFeatures(TaggerImpl *tagger) const;
  void rebuildFeatures(TaggerImpl *tagger) const;

  const char* what() { return what_.str(); }

  explicit FeatureIndex(): maxid_(0), alpha_(0), alpha_float_(0),
                           cost_factor_(1.0), xsize_(0), max_xsize_(0) {}
  virtual ~FeatureIndex() {}

 protected:
  virtual int getID(const char *str) const = 0;
  const char *get_index(const char *&p,
                        size_t pos,
                        const TaggerImpl &tagger) const;
  bool apply_rule(string_buffer *os,
                  const char *pattern,
                  size_t pos, const TaggerImpl &tagger) const;

  mutable unsigned int      maxid_;
  const double             *alpha_;
  const float              *alpha_float_;
  double                    cost_factor_;
  unsigned int              xsize_;
  mutable unsigned int              max_xsize_;
  std::vector<std::string>  unigram_templs_;
  std::vector<std::string>  bigram_templs_;
  std::vector<std::string>  y_;
  whatlog                   what_;
};

class EncoderFeatureIndex: public FeatureIndex {
 public:
  bool open(const char *template_filename,
            const char *model_filename);
  bool save(const char *filename, bool emit_textmodelfile);
  bool convert(const char *text_filename,
               const char *binary_filename);
  void shrink(size_t freq, Allocator *allocator);

 private:
  int getID(const char *str) const;
  bool openTemplate(const char *filename);
  bool openTagSet(const char *filename);

  mutable std::map<std::string, std::pair<int, unsigned int> > dic_;
};

class DecoderFeatureIndex: public FeatureIndex {
 public:
  bool open(const char *model_filename);

 private:
  Mmap <char> mmap_;
  Darts::DoubleArray da_;
  int getID(const char *str) const;
};
}
#endif
