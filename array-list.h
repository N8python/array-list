struct ArrayList {
  int max_length;
  int size;
  void ** data;
  void (*add)(struct ArrayList*, void*);
  void * (*get)(struct ArrayList*, int);
  void (*set)(struct ArrayList*, int, void*);
  void (*dub)(struct ArrayList *);
  void (*clear)(struct ArrayList *);
};

typedef struct ArrayList ArrayList;

ArrayList * new_ArrayList(int length);

void ArrayList_add(ArrayList * arr, void * val);

void * ArrayList_get(ArrayList * arr, int index);

void ArrayList_set(ArrayList * arr, int index, void * val);

void ArrayList_double(ArrayList * arr);

void ArrayList_clear(ArrayList * arr);

#ifndef listget
#define listget(type, list, index) *( (type*) list->get(list, index))
#endif

#ifndef listadd
#define listadd(type, list, val) { \
  type x = val; \
  list->add(list, &x); \
}
#endif

#ifndef listset
#define listset(type, list, index, val) { \
  type x = val; \
  list->set(list, index, &x); \
}
#endif
