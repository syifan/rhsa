__kernel void vector_add(__global float *in1, __global float *in2,
                         __global float *out) {
  uint tid = get_global_id(0);
  out[tid] = in1[tid] + in2[tid];
}
