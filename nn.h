typedef struct 
{
    float value;
    float weight;
}neuron_t;


typedef struct 
{
  int num_neurons;
  float bias;
  neuron_t *neuron; 

}layer_t;

typedef struct 
{
  int num_layers; 
  layer_t *layer;

}arch_t;