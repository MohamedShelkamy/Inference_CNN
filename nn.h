#define numlayers 1
#define numneurons 3
#define numinputs 3
#define numoutputs 1
#define MAX_SIZE 1000



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

void Forward_Propagation();
double sigmoid(double x);
void Read_data(double weight_table[numlayers + 1][numneurons][numneurons],double input_table[numinputs],double bias_table[numlayers + 1]);
