#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
    
    VectorXd rmse(estimations[0].size());
    rmse.fill(0.0);
    if (estimations.size() == 0 or estimations.size() != ground_truth.size())
    {
        return rmse;
    }
    //  * the estimation vector size should equal ground truth vector size
    // the length of rmse was 4, more generally it is the number of variables
    
    //accumulate squared residuals
    for(int i=0; i < estimations.size(); ++i)
    {
        // ... your code here
        VectorXd residuals = estimations[i] - ground_truth[i];
        residuals = residuals.array() * residuals.array();
        rmse += residuals;
    }
    
    //calculate the mean
    // ... your code here
    rmse = rmse / estimations.size();
    
    
    //calculate the squared root
    // ... your code here
    rmse = rmse.array().sqrt();
    //return the result
    return rmse;
}
