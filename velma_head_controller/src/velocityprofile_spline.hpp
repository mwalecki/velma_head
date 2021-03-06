#ifndef VELOCITYPROFILE_SPLINE_H
#define VELOCITYPROFILE_SPLINE_H

//#include "kdl/velocityprofile.hpp"
#include <iostream>

//namespace KDL
//{
	/**
	 * \brief A spline VelocityProfile trajectory interpolation.
	 * @ingroup Motion
	 */
class VelocityProfile_Spline //: public VelocityProfile
{
public:
    VelocityProfile_Spline();
    VelocityProfile_Spline(const VelocityProfile_Spline &p);

	virtual ~VelocityProfile_Spline();
	
    virtual void SetProfile(double pos1, double pos2);
    /**
     * Generate linear interpolation coeffcients.
     *
     * @param pos1 begin position.
     * @param pos2 end position.
     * @param duration duration of the profile.
     */
    virtual void SetProfileDuration(
      double pos1, double pos2, double duration);

    /**
     * Generate cubic spline interpolation coeffcients.
     *
     * @param pos1 begin position.
     * @param vel1 begin velocity.
     * @param pos2 end position.
     * @param vel2 end velocity.
     * @param duration duration of the profile.
     */
    virtual void SetProfileDuration(
      double pos1, double vel1, double pos2, double vel2, double duration);

    /**
     * Generate quintic spline interpolation coeffcients.
     *
     * @param pos1 begin position.
     * @param vel1 begin velocity.
     * @param acc1 begin acceleration
     * @param pos2 end position.
     * @param vel2 end velocity.
     * @param acc2 end acceleration.
     * @param duration duration of the profile.
     */
    virtual void SetProfileDuration(double pos1, double vel1, double acc1, double pos2, double vel2, double acc2, double duration);
    virtual double Duration() const;
    virtual double Pos(double time) const;
    virtual double Vel(double time) const;
    virtual double Acc(double time) const;
    virtual void Write() const;
    virtual VelocityProfile_Spline* Clone() const;
private:

    double coeff_[6];
    double duration_;
};
//}
#endif // VELOCITYPROFILE_SPLINE_H
