# Installation

    git clone git@github.com:matz-e/crab-fail-job.git Crab/Fail
    scram b

# Usage

In your python configuration, add:

    process.fail = cms.EDAnalyzer("Fail", jobid=cms.string("1"), retries=cms.int32(2))
    process.p = cms.Path(process.fail)

Or use the configuration in `test/pset.py`. The parameter `jobid`
deteremines which job fails, with `retries` failures before succeeding.
