/* See LICENSE file for copyright and license details. */

#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
/* u have to add -lm to the linker */
#include <math.h>

/* get dimension of an array */
#define DIM(X)        (sizeof X / sizeof X[0])

/* define a Vector */
typedef struct {
        int dim;
        double norm;
        double complex *arr;
} Vec;


/* define an option that check for error and return a double*/
typedef struct {
        int error;
        char *msg;
        double result;
} Option_double;


/* define an option that check for error and return a Vector */
typedef struct {
        int error;
        char *msg;
        Vec result;
} Option_vec;


/* get norm of a Vector */
double
get_norm(int dim, double complex* arr)
{
    double norm = 0;
    for (int i = 0; i < dim; i++) {
        norm += pow(cabs(arr[i]), 2);  /* Sum of squared magnitudes */
    }
    return sqrt(norm);
}

/* INIT a Vector */
Vec
new_vec(int dim, double complex* arr)
{
    if (dim <= 0 || arr == NULL) {
        fprintf(stderr, "Invalid vector initialization\n");
        exit(1);
    }

    Vec v = {
        dim,
	get_norm(dim, arr),
        arr  
    };
    return v;
}

void
print_vec(Vec* v, char* name)
{
    printf("Vec %s (\nArray:\n", name);
    for (int i = 0; i < v->dim; i++) {
        printf("\t%f + %fi\n", creal(v->arr[i]), cimag(v->arr[i]));
    }
    printf("Norm:\t%f\n", v->norm);
    printf("Dim:\t%d\n", v->dim);
    puts(")\n");
}

/*
 * Calculates the dot product of two vectors.
 * @param self Pointer to the first vector.
 * @param other Pointer to the second vector.
 * @return Option_double containing the result or an error message.
 */
Option_double
dot_product(Vec* self, Vec* other)
{
    if (self->dim != other->dim) {
        Option_double ret = {1, "Both dimensions must be equal", 0};
        return ret;
    }

    double complex res = 0;
    for (int i = 0; i < self->dim; i++) {
        res += self->arr[i] * conj(other->arr[i]);  /* Dot product with conjugate */
    }

    Option_double ret = {0, "", creal(res)};  /* Return real part of the result */
    return ret;
}

/* define cross product for two 3D Vectors */
Option_vec
cross_product(Vec* self, Vec* other, double* arr)
{
    if (self->dim != 3 || other->dim != 3) {
        Option_vec ret = {1, "Both vectors must be 3-dimensional for cross product", {}};
        return ret;
    }

    arr[0] = self->arr[1] * other->arr[2] - self->arr[2] * other->arr[1];
    arr[1] = self->arr[2] * other->arr[0] - self->arr[0] * other->arr[2];
    arr[2] = self->arr[0] * other->arr[1] - self->arr[1] * other->arr[0];

    Option_vec ret = {0, "", {3, get_norm(3, arr), arr}};
    return ret;
}

/* define addition on tow Vectors */
Option_vec
add_vec(Vec* self, Vec* other, double complex *arr)
{
    if (self->dim != other->dim) {
        Option_vec ret = {1, "Both dimensions must be equal", {}};
        return ret;
    }
    int dim = self->dim;
    for (int i = 0; i < dim; i++) {
        arr[i] = self->arr[i] + other->arr[i];
    }
    Option_vec ret = {0, "", {dim, get_norm(dim, arr), arr}};
    return ret;
}


/* define substitution on tow Vectors */
Option_vec
sub_vec(Vec* self, Vec* other, double *arr)
{
        if (self->dim != other->dim) {
                Option_vec ret = {1, "Both dimensions must be equal", {}};
                return ret;
        }
	int dim = self->dim;
        for (int i=0; i<dim; i++)
                arr[i] = (self->arr[i] - other->arr[i]);
        Option_vec ret = {0, "", {dim, get_norm(dim, arr), arr}};
        return ret;
}

int
isorthogonal(Vec* self, Vec* other)
{
        Option_double dot = dot_product(self, other);
        if (dot.error == 0)
		return dot.result == 0;
	printf("Err: %s\n", dot.msg);
	exit(1);	
}

int
main()
{
        double complex a[] = {0, 1, 0};
        double complex b[] = {0, 0, 1};
	double complex c[DIM(a)];
        Vec v = new_vec(DIM(a), a);
        Vec w = new_vec(DIM(b), b);
        print_vec(&v, "V");
        print_vec(&w, "W");
	puts("Addition of V+W:");
        Option_vec u = add_vec(&v, &w, c);
        if (u.error == 0)
		print_vec(&u.result, "U");
        else {
                printf("Err: %s\n", u.msg);
		exit(1);
	}

        Option_double res = dot_product(&v, &w);
        if (res.error == 0)
                printf("Dot Product of V.W: %f\n", res.result );
        else {
                printf("Err: %s\n", res.msg);
		exit(1);
	}	
	Option_vec cross = cross_product(&v, &w, c);
	if (cross.error == 0)
 	   print_vec(&cross.result, "Cross Product of VxW");
	else {
	    printf("Err: %s\n", cross.msg);
	    exit(1);
	}
	
	printf("Are V & W orthogonal? %d\n", isorthogonal(&v, &w));
	return 0;
}
