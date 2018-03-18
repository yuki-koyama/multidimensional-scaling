// Copyright (C) 2015-2018 Yuki Koyama
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

#include <vector>
#include <utility>
#include <cassert>
#include <Eigen/Core>
#include <Eigen/Eigenvalues>

namespace MDS
{

// This function computes low-dimensional embedding by using multi-dimensional scaling (MDS)
// - Input:  A distance (dissimilarity) matrix and a target dimension for embedding
// - Output: A coordinate matrix whose i-th column corresponds to the embedded coordinates of the i-th entry
extern inline Eigen::MatrixXd computeMDS(const Eigen::MatrixXd& D, unsigned dim);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

// This function extract the N-largest eigen values and eigen vectors
inline void extractNLargestEigens(unsigned n, Eigen::VectorXd& S, Eigen::MatrixXd& V)
{
    // Note: m is the original dimension
    const unsigned m = S.rows();

    // Copy the original matrix
    const Eigen::MatrixXd origV = V;

    // Sort by eigenvalue
	constexpr double epsilon = 1e-16;
    std::vector<std::pair<double, unsigned>> sortS(m);
    for (unsigned i = 0; i < m; ++ i) sortS[i] = std::make_pair(std::max(S(i), epsilon), i);
    std::partial_sort(sortS.begin(), sortS.begin() + n, sortS.end(), std::greater<std::pair<double, unsigned>>());

    // Resize matrices
    S.resize(n);
    V.resize(m, n);

    // Set values
    for (unsigned i = 0; i < n; ++ i)
    {
        S(i)     = sortS[i].first;
        V.col(i) = origV.col(sortS[i].second);
    }
}

inline Eigen::MatrixXd computeMDS(const Eigen::MatrixXd& D, unsigned dim)
{
    assert(D.rows() == D.cols());
    assert(D.rows() >= dim);
    const unsigned n = D.rows();
    const Eigen::MatrixXd H = Eigen::MatrixXd::Identity(n, n) - (1.0 / static_cast<double>(n)) * Eigen::VectorXd::Ones(n) * Eigen::VectorXd::Ones(n).transpose();
    const Eigen::MatrixXd K = - 0.5 * H * D * H;
    const Eigen::EigenSolver<Eigen::MatrixXd> solver(K);
    Eigen::VectorXd S = solver.eigenvalues().real();
    Eigen::MatrixXd V = solver.eigenvectors().real();
    extractNLargestEigens(dim, S, V);
    const Eigen::MatrixXd X = Eigen::DiagonalMatrix<double, Eigen::Dynamic>(S.cwiseSqrt()) * V.transpose();
    return X;
}

}

#endif // MDS_H
