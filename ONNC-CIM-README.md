## Preface

This is a joint work between Skymizer Taiwan Inc. and the Embedded Computing Lab at National Taiwan University.  This project uses the [Open Neural Netowrk Compiler](https://github.com/ONNC/onnc) as a frontend  to parse an ONNX  model and generate workloads to a CIM hardware simulator with a detailed crossbar device error model.  The goal is to provide a modeling framework to facilitate CIM research projects. This project aims to create a simulator for researcher to inspect the crossbar performance in a CIM architecture. onnc-cimHW provides a fast tool to evaluate device characteristics. Users are welcome to extend this project for research and share with our community.  

## Contributors: 

### Skymizer
- Jen-ho Kuo 
- Der-Yu Tsai
- Yu-Jie Wang 
- Wei-Fen Lin 

### Embedded Computing Lab @ Nation Taiwan University 
- Meng-Yao Lin
- Wei-Ting Lin
- Tzu-Hsien Yang
- I-Ching Tseng
- Hsiang-Yun Cheng 
- Chia-Lin Yang


## Acknowledgement 
When using the ONNC-CIM toolset, please cite the following two papers:

- [1] Lin, M., Cheng, H., Lin, W., Yang, T., Tseng, I., Yang, C., Hu, H., Chang, H., Li, H., & Chang, M. (2018). DL-RSIM: A Simulation Framework to Enable Reliable ReRAM-based Accelerators for Deep Learning. 2018 IEEE/ACM International Conference on Computer-Aided Design (ICCAD), 1-8.

- [2] W. F. Lin, D. Y. Tsai, L. Tang, C. T. Hsieh, C. Y. Chou, P. H. Chang, and L. Hsu, “ONNC: A compilation framework connecting ONNX to proprietary deep learning accelerators,” in IEEE International Conference on Artificial Intelligence Circuits and Systems (AICAS 2019). IEEE, 2019.
