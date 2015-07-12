// Copyright (C) 2015 Yuki Koyama
//
// MIT License: 
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef MDS_H
#define MDS_H

#include <Eigen/Core>

namespace MDS
{
// This function computes low-dimensional embedding by using multi-dimensional scaling (MDS)
// - Input:  A distance (dissimilarity) matrix and a target dimension for embedding
// - Output: A coordinate matrix whose i-th column corresponds to the embedded coordinates of the i-th entry
Eigen::MatrixXd computeMDS(const Eigen::MatrixXd& D, unsigned dim);
}

#endif // MDS_H
