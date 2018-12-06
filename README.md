
* Some File List

gold/       Contains the gold standard segmentation of the test data
            along with the training data word lists.

scripts/    Contains the scoring script and simple segmenter.

testing/    Contains the unsegmented test data.

training/   Contains the segmented training data.

doc/        Contains the instructions used in the bakeoff.

* Encoding Issues

Files with the extension ".utf8" are encoded in UTF-8 Unicode.

Files with the extension ".txt" are encoded as follows:

as_    Big Five (CP950)
hk_    Big Five/HKSCS
msr_   EUC-CN (CP936)
pku_   EUC-CN (CP936)

EUC-CN is often called "GB" or "GB2312" encoding, though technically
GB2312 is a character set, not a character encoding.

* Scoring

The script 'score' is used to generate compare two segmentations. The
script takes three arguments:

1. The training set word list
2. The gold standard segmentation
3. The segmented test file




* Invoking the scoring script：

@@@Jieba
perl scripts/score gold/CTB7_training_words.utf8 gold/CTB7_testing_gold.utf8 result/jieba/CTB7_result.utf8 > score/jieba/jieba_CTB7.utf8

perl scripts/score gold/as_training_words.utf8 gold/as_testing_gold.utf8 result/jieba/as_result.utf8 > score/jieba/jieba_as.utf8

perl scripts/score gold/cityu_training_words.utf8 gold/cityu_test_gold.utf8 result/jieba/cityu_result.utf8 > score/jieba/jieba_cityu.utf8

perl scripts/score gold/msr_training_words.utf8 gold/msr_test_gold.utf8 result/jieba/msr_result.utf8 > score/jieba/jieba_msr.utf8

perl scripts/score gold/pku_training_words.utf8 gold/pku_test_gold.utf8 result/jieba/pku_result.utf8 > score/jieba/jieba_pku.utf8
@@@

@@@HLseg
perl scripts/score gold/CTB7_training_words.utf8 gold/CTB7_testing_gold.utf8 result/hlseg/CTB7_result.utf8 > score/hlseg/hlseg_CTB7.utf8

perl scripts/score gold/as_training_words_jt.utf8 gold/as_testing_gold_jt.utf8 result/hlseg/as_result.utf8 > score/hlseg/hlseg_as.utf8

perl scripts/score gold/cityu_training_words_jt.utf8 gold/cityu_test_gold_jt.utf8 result/hlseg/cityu_result.utf8 > score/hlseg/hlseg_cityu.utf8

perl scripts/score gold/msr_training_words.utf8 gold/msr_test_gold.utf8 result/hlseg/msr_result.utf8 > score/hlseg/hlseg_msr.utf8

perl scripts/score gold/pku_training_words.utf8 gold/pku_test_gold.utf8 result/hlseg/pku_result.utf8 > score/hlseg/hlseg_pku.utf8
@@@

@@@DLseg
perl scripts/score gold/CTB7_training_words.utf8 gold/CTB7_testing_gold.utf8 result/dlseg/CTB7_result.utf8 > score/dlseg/dlseg_CTB7.utf8

perl scripts/score gold/as_training_words_jt.utf8 gold/as_testing_gold_jt.utf8 result/dlseg/as_result.utf8 > score/dlseg/dlseg_as.utf8

perl scripts/score gold/cityu_training_words_jt.utf8 gold/cityu_test_gold_jt.utf8 result/dlseg/cityu_result.utf8 > score/dlseg/dlseg_cityu.utf8

perl scripts/score gold/msr_training_words.utf8 gold/msr_test_gold.utf8 result/dlseg/msr_result.utf8 > score/dlseg/dlseg_msr.utf8

perl scripts/score gold/pku_training_words.utf8 gold/pku_test_gold.utf8 result/dlseg/pku_result.utf8 > score/dlseg/dlseg_pku.utf8
@@@
